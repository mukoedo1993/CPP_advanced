Prefer nullptr to 0 and NULL.

Using nullptr instead of 0 or NULL thus avoids overload resolution surprises, but that's not its 
only advantage. It can also improve code clarity, esp. when auto variables are involved.
