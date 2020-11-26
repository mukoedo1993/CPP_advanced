https://docs.microsoft.com/en-us/cpp/standard-library/vector-bool-class?view=msvc-160
vector<bool> is a specialized class of template class vector<T>.

Notice that vector<bool>::operator[] will return a nested class vector<bool>::reference rather than a bool& type.
However, static_cast<bool> is allowed to apply here to get the correct result.
