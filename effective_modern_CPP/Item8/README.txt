Prefer nullptr to 0 and NULL.

Using nullptr instead of 0 or NULL thus avoids overload resolution surprises, but that's not its 
only advantage. It can also improve code clarity, esp. when auto variables are involved.


In contrast, the call involving nullptr has no trouble. When nullptr is passed to lockAndCall, the
type for ptr is deduced to be std::nullptr_t. When ptr is passed to f3, there's an implicit conversion from std::nullptr_t to
Widget*, because std::nullptr_t implicitly converts to all pointer types.

Avoid overloading on integral and pointer types.
