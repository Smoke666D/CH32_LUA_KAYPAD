#pragma once

#include "hal_can.h"

template <uint8_t _filter_count> class cpp_filter_count
{
    protected:
uint8_t std_filter_pointer;
uint8_t extd_filter_pointer;

    public:
  cpp_filter_count():
  std_filter_pointer(0),
  extd_filter_pointer(_filter_count)
  {}
   bool std_filter_add(uint32_t _filter)
   {
        if (((std_filter_pointer + 1) / 2) < extd_filter_pointer )
        {
            std_filter_pointer++;
        }
   }
   bool extd_filter_add(uint32_t _filter)
   {
        if ((extd_filter_pointer-1) > std_filter_pointer )
        {
            std_filter_pointer--;
        }
   }

};
