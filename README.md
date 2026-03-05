# CPP06 Its All About C++ Casts

There are 4 cast types need to master

### Static_cast
	# compile-time conversions between related types
		> Converting ***double into int *** or vice versa
		> Upcasting/Downcasting in a class hierarchy(no runtime check)
		> Safe when you know the types of compatible

### reinterpret_cast
	# this type of casting is reinterpretation of raw bits, its not a conversion
		> Pointer to pointer of unrelated types
		> Pointer to integer
		> *** Dangerous***

### const_cast
	# This cast is the only one that can remove or add ***cast***
		> Useful when i know i want a non-const with const pointer that i know won't be modified
		> but if an original-const object modification will result in undefined behavior

### dynamic_cast
	# So this cast is for Polymorphic class hierarchies(atleast 1 virtual function)
		> Returns nullptr(pointer) or throws std::bad_cast(references) when fail
		> Only cast that is runtime-safe for downcasting

