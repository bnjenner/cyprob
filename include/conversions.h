#pragma once

#include <iomanip>
#include <sstream>
#include <pybind11/pybind11.h>
#include "definitions.h"

/*

  BNJ - NOTE: This is a modified version of the code from 
            this forum: https://stackoverflow.com/questions/54738011/pybind11-boostmultiprecisioncpp-int-to-python
            Thanks to everyone on this forum.

*/

namespace pybind11 {
  namespace detail {
    template <>
    struct type_caster<boost_int> {

      /**
       * This macro establishes the name 'boost_int' in function signatures and 
       * declares a local variable 'value' of type boost_int
       * 
       * Convert an boost_int instance into a Python object. 
       * The second and third arguments are used to indicate the 
       * return value policy and parent object (for 
       * ``return_value_policy::reference_internal``) and are generally ignored 
       * by implicit casters.
       */

      PYBIND11_TYPE_CASTER(boost_int, _("boost_int"));
      static handle cast(const boost_int& src, return_value_policy, handle) {
       
        // First try to use the builtin long long conversion
        if (src <= std::numeric_limits<long long>::max() && 
            src >= std::numeric_limits<long long>::min()) {
          return PyLong_FromLongLong(static_cast<long long>(src));
        }

        // Otherwise convert to base 16 string
        std::ostringstream oss;
        if (src < 0) {
          oss << '-' << std::hex << -src; // boost does not like negative hex strings
        } else {
          oss << std::hex << src;  
        }
        return PyLong_FromString(oss.str().c_str(), nullptr, 16);
      }
    };
  }
}