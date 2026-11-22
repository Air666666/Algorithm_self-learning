#define main original_main
#include "../../../src/class039/Code02_DecodeString.cpp"
#undef main
int main(){jout.println(Code02_DecodeString::decodeString(String(u"3[a]2[bc]")));jout.println(Code02_DecodeString::decodeString(String(u"3[a2[c]]")));jout.println(Code02_DecodeString::decodeString(String(u"2[abc]3[cd]ef")));jout.println(Code02_DecodeString::decodeString(String(u"abc3[cd]xyz")));}