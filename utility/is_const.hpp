#pragma once

namespace my_stl {
  // Determines whether a type is const-qualified.
  template<typename T>
  struct is_const {
      static constexpr bool value = false;
  };

  // Specialization for const-qualified types.
  template<typename T>
  struct is_const<const T> {
      static constexpr bool value = true;
  };
}
