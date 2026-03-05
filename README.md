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
	# A simple concept that make Pointer -> Number-> Pointer


### const_cast
	# This cast is the only one that can remove or add ***cast***
		> Useful when i know i want a non-const with const pointer that i know won't be modified
		> but if an original-const object modification will result in undefined behavior

### dynamic_cast
	# So this cast is for Polymorphic class hierarchies(atleast 1 virtual function)
		> Returns nullptr(pointer) or throws std::bad_cast(references) when fail
		> Only cast that is runtime-safe for downcasting


		Sending Data Over Network**
	```
	C++ Object (in memory):
	struct Person {
		std::string name = "Alice";
		int age = 30;
	}

	↓ SERIALIZE ↓

	JSON string (can be sent over internet):
	{"name":"Alice","age":30}

	↓ DESERIALIZE ↓

	C++ Object (reconstructed on another computer):
	struct Person {
		std::string name = "Alice";
		int age = 30;
	}
 In THIS Exercise (Ex01)**

**Your specific case:**
	```
	Data Object (in memory):
	Address: 0x7fff5fbff710 ← This is a POINTER
	Content: { value: 42, str: "Hello" }

	↓ SERIALIZE ↓

	Number (can be stored/transmitted):
	140734799737616  ← The pointer converted to a number!

	↓ DESERIALIZE ↓

	Pointer (reconstructed):
	Address: 0x7fff5fbff710 ← Same pointer!
	Content: { value: 42, str: "Hello" }
