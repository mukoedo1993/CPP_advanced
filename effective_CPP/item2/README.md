enum-hack<br>

# Conclusions:
1:For simple constants, prefer const objects or enums to #define<br>
2: For function-like macros, prefer inline functions to #defines<br>
See [here](https://stackoverflow.com/questions/20660372/operator-applied-two-times-depending-on-arguments-to-define-function) for the tricky part:
`
CALL_WITH_MAX(++a,b)
`
expands to
`
((++a) > (b) ? (++a) : (b))
`
