#define main original_main
#include "../../../src/class039/Code03_NumberOfAtoms.cpp"
#undef main
int main(){jout.println(Code03_NumberOfAtoms::countOfAtoms(String(u"H2O")));jout.println(Code03_NumberOfAtoms::countOfAtoms(String(u"Mg(OH)2")));jout.println(Code03_NumberOfAtoms::countOfAtoms(String(u"K4(ON(SO3)2)2")));}