#ifndef SCOPED_ENUMS2_HPP
#define SCOPED_ENUMS2_HPP
enum class Status:long long int;//forward declaration
void continueProcessing(Status s);//use of fwd-delcared enum
#endif
/*
Yje jeader containing these declarations requires no recompilation if
Status's definition is revised. Furthermore, if Status is modified (e.g.,
to add the audited enumerator), but continueProcessing's behavior is unaffected
(e.g. because continueProcessing doesn't use audited), continueProcessing's implemenation
need not be recompiled, either.
*/