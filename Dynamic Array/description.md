# Description

Dynamic Array (dynamic_array<>) is a std::vector<> replacement capable to handle operations like:
- getting different properties of the array:
  - getting the size: ***.size()***
  - getting the capacity: ***.capacity()***
  - checking if the array is empty: ***.empty()***
- modifying the whole array:
  - resizing the array: ***.resize()***
  - assigning a size and a value to the array: ***.assign()***
  - clearing the array ***.clear()***
- accessing/modifying:
  - any element: ***.operator[]***
  - the first element: ***.front()***
  - the last element: ***.back()***
- appending elements to the array: ***.push_back()***
- removing the last element of the array: ***.pop_back()***
