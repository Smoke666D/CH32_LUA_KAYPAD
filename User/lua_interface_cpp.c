

#include "lua_interface_cpp.h"
#include "lprefix.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "lapi.h"
#include "hw_lib_can.h"
#include "hal_timers.h"
#include "led_task.h"
#include "io_task.h"
#include "string.h"
#include "hal_wdt.h"


/* 
Static function
*/
static int iCanSetConfig(lua_State *L);
static int iCanSendData( lua_State *L );
static int iCanSetResiveFilter(lua_State *L );
static int iCanGetResivedData(lua_State *L );
static int iCanResetResiveFilter(lua_State *L );
static int iCanCheckData( lua_State *L );
static int iSetCanNodeID( lua_State *L );
static int iGetKeyMask(lua_State *L);
static int iSetLedRed(lua_State *L);
static int iSetLedGreen(lua_State *L);
static int iSetLedBlue(lua_State *L);
static int iSetBackBrigth(lua_State *L);
static int iSetBackColor(lua_State *L);
static int iSetLedBrigth(lua_State *L);


static const luaL_Reg dev_funcs[] = {
  {"Send",           iCanSendData          },
  {"CheckFilter",    iCanCheckData         },
	{"GetFrame",       iCanGetResivedData    },
  {"SetFilter",      iCanSetResiveFilter   },
  {"ResetFilter",    iCanResetResiveFilter },
	{"Config",         iCanSetConfig         },
  {"SetNodeID",      iSetCanNodeID         },
  {"GetKeys",     iGetKeyMask}, 
  {"SetLedRed",   iSetLedRed },
  {"SetLedGreen", iSetLedGreen },
  {"SetLedBlue",  iSetLedBlue },
  {"SetLedBrigth", iSetLedBrigth},
  {"SetBackColor", iSetBackColor},
  {"SetBackBrigth", iSetBackBrigth},
  {NULL, NULL}
};

LUAMOD_API int luaopen_dev (lua_State *L) {
  luaL_newlib(L, dev_funcs);
  return 1;
}

static const luaL_Reg userlibs[] = {

  {"Keypad8", luaopen_dev  },
  {NULL, NULL}
};


LUALIB_API void luaL_openuser (lua_State *L) {
  const luaL_Reg *lib;
  /* "require" functions from 'loadedlibs' and set results to global table */
  for (lib = userlibs; lib->func; lib++) {
    luaL_requiref(L, lib->name, lib->func, 1);
    lua_pop(L, 1);  /* remove lib */
  }
}


/*
§¶§å§ß§Ü§è§Ú§ñ §à§ä§á§â§Ñ§Ó§Ü§Ú §á§Ñ§Ü§Ö§ä§Ñ §á§à CAN. §£§Ñ§â§Ú§Ñ§ä§Ú§Ó§ß§à§Ö §Ü§à§Ý-§Ó§à §Ñ§Ô§â§å§Þ§Ö§ß§ä§à§Ó, §Ó §Ù§Ñ§Ó§Ú§Þ§à§ã§ä§Ú §à§ä DLC §æ§â§Ö§Û§Þ§Ñ §Ú§Ý§Ú §á§Ö§â§Ö§Õ§Ñ§é§Ú §Õ§Ñ§ß§ß§í§ç §Ó §ä§Ñ§Ò§Ý§Ú§è§Ö
*/
static int iCanSendData( lua_State *L )
{
    CAN_TX_FRAME_TYPE frame ={0};
    int parametr_count = lua_gettop(L);
    if ( parametr_count>= THREE_ARGUMENTS )
    {
        frame.rtr   = (uint32_t)lua_tointeger(L, THIRD_ARGUMENT);
        frame.extd  = (uint32_t)lua_tointeger(L, SECOND_ARGUMENT);
        frame.ident = (uint32_t)lua_tointeger(L, FIRST_ARGUMENT);
        if (parametr_count >= FOUR_ARGUMENTS )
        {
            if (lua_istable(L, LAST_ARGUMENT))   //§±§â§à§Ó§Ö§â§ñ§Ö§Þ §é§ä§à §Ó §Ü§Ñ§é§Ö§ã§ä§Ó§Ö §Ñ§â§Ô§å§Þ§Ö§ß§ä§Ñ §á§Ö§â§Ö§Õ§Ñ§Ý§Ú §ä§Ñ§Ò§Ý§Ú§è§å
            { 	
			          frame.DLC 	 = luaL_len(L, LAST_ARGUMENT);  //§¹§Ú§ä§Ñ§Ö§Þ §â§Ñ§Þ§Ö§â §ä§Ñ§Ò§Ý§Ú§è§í
                if (frame.DLC  > CAN_FRAME_SIZE) frame.DLC = 8;
				        for (uint8_t i = 0; i < frame.DLC ; i++)
				        {
					        lua_geti(L, LAST_ARGUMENT , i +1 );               //§±§à§Ý§å§é§Ñ§Ö§Þ §ï§Ý§Ö§Þ§Ö§ß§ä §ä§Ñ§Ò§Ý§Ú§è§í
					        frame.data[i]=   lua_tointeger(L,LAST_ARGUMENT);  //§£§í§ä§Ñ§ã§Ü§Ú§Ó§Ñ§Ö§Þ §Õ§Ñ§ß§ß§í§Ö §Ú§Ù §ä§Ñ§Ò§Ý§Ú§è§í
                  lua_pop(L,1);                                     //§µ§Ò§Ú§â§Ñ§Ö§Þ §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §Ú§Ù §ã§ä§Ö§Ü§Ñ
                }
            }
            else 
            {
              frame.DLC =  parametr_count - THREE_ARGUMENTS;
              if (frame.DLC  > CAN_FRAME_SIZE) frame.DLC = 8;
              for (int i=0; i< (frame.DLC) ;i++)
		          {
			            frame.data[i]= (uint8_t) lua_tointeger(L,-( frame.DLC-i)); 
		          }
          }                        
				}
				APPCANSEND(&frame);
			}
	  return ( NO_RESULT );
}

/*
§ª§ß§Ú§è§Ú§Ñ§Ý§Ú§Ù§Ñ§è§Ú§ñ §Ü§à§ß§ä§â§Ý§Ý§Ö§â§Ñ CAN
*/
static int iCanSetConfig(lua_State *L)
{
  if (lua_gettop(L) == ONE_ARGUMENT)
  {
	  vCANBoudInit( (uint16_t)lua_tointeger( L, FIRST_ARGUMENT) );
  }
	return ( NO_RESULT );
}
/*
§ª§ß§Ú§è§Ú§Ñ§Ý§Ú§Ù§Ñ§è§Ú§ñ §Ü§à§ß§ä§â§Ý§Ý§Ö§â§Ñ CAN
*/
static int iSetCanNodeID(lua_State *L)
{
	if (lua_gettop(L) == ONE_ARGUMENT)
	{
    ConfigNodeID( (uint8_t) lua_tointeger( L, FIRST_ARGUMENT)); 
	}
	return ( NO_RESULT );
}

static int iGetKeyMask(lua_State *L)
{
    lua_pushinteger(L, getKeyData());
    return ( ONE_RESULT );
}

static int iSetLedRed(lua_State *L)
{
  int res;
  uint8_t data = lua_tointegerx(L,LAST_ARGUMENT, &res);
  if  (res ==  1)
  {
      vSetLedOn(RED,data);
  }
  return ( NO_RESULT );
}

static int iSetLedGreen(lua_State *L)
{
   int res;
  uint8_t data = lua_tointegerx(L,LAST_ARGUMENT, &res);
  if  (res ==  1)
  {
    	
      vSetLedOn(GREEN,data);
  }
  return ( NO_RESULT );
}

static int iSetLedBlue(lua_State *L)
{
  if  (lua_gettop(L) == ONE_ARGUMENT)
  {
      vSetLedOn(BLUE,lua_tointeger(L,LAST_ARGUMENT ));
  }
  return ( ONE_RESULT );
}

static int iSetBackBrigth(lua_State *L)
{
  if  (lua_gettop(L) == ONE_ARGUMENT)
  {
      vSetBackLigth(lua_tointeger(L,LAST_ARGUMENT ));
  }
  return ( ONE_RESULT );
}
static int iSetBackColor(lua_State *L)
{
  if  (lua_gettop(L) == ONE_ARGUMENT)
  {
    vSetBackLigthColor(lua_tointeger(L,LAST_ARGUMENT ));
  }
  return ( ONE_RESULT );
}
static int iSetLedBrigth(lua_State *L)
{
  if  (lua_gettop(L) == ONE_ARGUMENT)
  {
    vSetLedBrigth(lua_tointeger(L,LAST_ARGUMENT ));
  }
  return ( ONE_RESULT );
}


/*
§¶§å§ß§Ü§è§Ú§ñ §å§ã§ä§Ñ§ß§à§Ó§Ü§Ú CAN §æ§Ú§Ý§î§ä§à§â§Ó
*/
static int iCanSetResiveFilter(lua_State *L )
{
  uint8_t ucResNumber = NO_RESULT;
  if (lua_gettop(L) == THREE_ARGUMENTS )  /*§±§â§à§Ó§Ö§â§ñ§Ö§Þ, §é§ä§à §á§â§Ú §Ó§í§Ù§à§Ó§Ö §ß§Ñ§Þ §á§Ö§â§Ö§Õ§Ñ§Ý§Ú §ß§å§Ø§ß§à§Ö §é§Ú§ã§Ý§à §Ñ§â§Ô§å§Þ§Ö§ß§ä§à§Ó*/
  {
	  lua_pushnumber(L, eMailboxFilterSet( ( uint32_t ) lua_tointeger(L,FIRST_ARGUMENT ),
                                                      lua_tointeger(L,SECOND_ARGUMENT ),
                                                      lua_tointeger(L,THIRD_ARGUMENT )
                                                      ) );
	  ucResNumber = ONE_RESULT;
  }
  return ( ucResNumber );
}

/*
§¶§å§ß§Ü§è§Ú§ñ §ã§Ò§â§à§ã§Ñ §æ§Ú§Ý§î§ä§â§Ñ CAN
*/
static int iCanResetResiveFilter(lua_State *L )
{
  if (lua_gettop(L) == ONE_ARGUMENT )  /*§±§â§à§Ó§Ö§â§ñ§Ö§Þ, §é§ä§à §á§â§Ú §Ó§í§Ù§à§Ó§Ö §ß§Ñ§Þ §á§Ö§â§Ö§Õ§Ñ§Ý§Ú §ß§å§Ø§ß§à§Ö §é§Ú§ã§Ý§à §Ñ§â§Ô§å§Þ§Ö§ß§ä§à§Ó*/
  {
    eMailboxFilterReset(  lua_tointeger(L,FIRST_ARGUMENT) );
  }
  return ( NO_RESULT );
}

/*
§¶§å§ß§Ü§è§Ú§ñ §á§â§à§Ö§â§Ü§Ú §á§â§Ú§ê§Ý§Ö §Ý§Ú §ß§å§Ø§ß§í§Û §á§Ñ§Ü§Ö§ä
§£ §Ü§Ñ§é§Ö§ã§ä§Ó§Ö §á§Ñ§â§Ñ§Þ§Ö§ä§â§Ñ §á§Ö§â§Ö§Õ§Ñ§Ö§ä§ã§ñ CAN_ID §Õ§Ý§ñ §á§â§à§Ó§Ö§â§Ü§Ú. §£ §ã§Ý§å§é§Ñ§Ö §Ö§ã§Ý§Ú §á§Ñ§â§Ñ§Þ§Ö§ä§â§à§Ó §ß§Ö §á§Ö§â§Ö§Ñ§Õ§ß§à,
§á§â§à§Ó§Ö§â§ñ§Ö§ä§î§ã§ñ §æ§Ú§Ý§î§ä§â, §å§ã§ä§Ñ§ß§à§Ó§Ý§Ö§ß§ß§í§Û §â§Ñ§ß§Ö§Ö §æ§å§ß§Ü§è§Ú§Ö§Û iCanSendRequest
*/
static int iCanCheckData(lua_State *L )
{
	uint32_t uiRes = 0U;
	if (lua_gettop(L) == ONE_ARGUMENT ) 
  {
		  uiRes =  uCheckMailBoxData( lua_tointeger(L, FIRST_ARGUMENT));                                   		 
	}
	lua_pushnumber(L, uiRes );
	return ( 1U );
}


/*
§¶§å§ß§Ü§è§Ú§ñ §á§à§Ý§å§é§Ñ§Ö§ß§Ú§ñ §á§Ñ§Ü§Ö§ä CAN 
*/
static int iCanGetResivedData(lua_State *L )
{
	uint8_t n;
  uint8_t res = 0;
  int8_t mail_box_index= 0;
	CAN_FRAME_TYPE  RXPacket;
	if (lua_gettop(L) >= ONE_ARGUMENT )
	{
    mail_box_index = lua_tointeger(L,FIRST_ARGUMENT );
   
    if  ( GetMailBoxData( mail_box_index,&RXPacket ) == 1 )
    {
      if ((lua_gettop(L)==TWO_ARGUMENTS) && lua_istable(L, LAST_ARGUMENT))   //§±§â§à§Ó§Ö§â§ñ§Ö§Þ §é§ä§à §Ó §Ü§Ñ§é§Ö§ã§ä§Ó§Ö §Ñ§â§Ô§å§Þ§Ö§ß§ä§Ñ §á§Ö§â§Ö§Õ§Ñ§Ý§Ú §ä§Ñ§Ò§Ý§Ú§è§å
      { 
	      n = luaL_len(L, -1);
	    	for (int i = 1; i<(n+1);i++)
	    	{
	    	  lua_pushnumber(L,RXPacket.data[i-1]);
	    		lua_seti(L, -2, i);
	      }
	    	res = 1U;
      }
      else 
      {	    
		    res = RXPacket.DLC;
		    for (int i = 0; i < res;i++)
		    {
			    lua_pushnumber(L,RXPacket.data[i]);
		    }
        return (res );
      }      
    }
	}
  lua_pushnumber(L,res );
	return ( 1U );
}
