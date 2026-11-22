#include <cassert>
#include <sstream>
#define main kattio_demo
#include "../src/class019/Code05_Kattio.cpp"
#undef main
#define main fastio_demo
#include "../src/class019/Code06_FastReaderWriter.cpp"
#undef main
int main(){
 std::istringstream in("hello 2147483647 131237128371723187 5.6920E+0001");std::ostringstream out;
 Code05_Kattio::Kattio io(in,out);assert(io.next()=="hello");assert(io.nextInt()==INT_MAX);assert(io.nextLong()==131237128371723187LL);assert(io.nextDouble()==56.92);assert(!io.next());io.println("ok");io.flush();assert(out.str()=="ok\n");
 FILE* f=std::tmpfile();assert(f);
 {Code06_FastReaderWriter::FastWriter w(f);for(long long x:{LLONG_MIN,LLONG_MAX,0LL,-1LL,131237128371723187LL})w.println(x);for(int i=0;i<5000;++i)w.println(i);w.close();}
 std::rewind(f);Code06_FastReaderWriter::FastReader r(f);
 for(long long x:{LLONG_MIN,LLONG_MAX,0LL,-1LL,131237128371723187LL})assert(r.readLong()==x);
 for(int i=0;i<5000;++i)assert(r.readInt()==i);
 bool eof=false;try{r.readLong();}catch(const std::runtime_error&){eof=true;}assert(eof);std::fclose(f);
 f=std::tmpfile();assert(f);std::fputs("9223372036854775808",f);std::rewind(f);Code06_FastReaderWriter::FastReader bad(f);bool overflow=false;try{bad.readLong();}catch(const std::out_of_range&){overflow=true;}assert(overflow);std::fclose(f);
}
