// Source: algorithmzuo/algorithm-journey/src/class019/Code06_FastReaderWriter.java
// C++ 缓冲快读/快写：FILE* 对应字节流；整数解析覆盖完整 int64 范围。
#include <array>
#include <charconv>
#include <climits>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
struct Code06_FastReaderWriter {
 struct FastReader {
  FILE* in;std::array<unsigned char,1024> buf{};size_t pos=0,len=0;
  explicit FastReader(FILE* f=stdin):in(f){if(!f)throw std::invalid_argument("null stream");}
  int readByte(){if(pos==len){len=std::fread(buf.data(),1,buf.size(),in);pos=0;if(!len)return EOF;}return buf[pos++];}
  long long readLong(){
   int c;do{c=readByte();}while(c!=EOF&&c!='-'&&(c<'0'||c>'9'));
   if(c==EOF)throw std::runtime_error("unexpected EOF");
   bool neg=c=='-';if(neg)c=readByte();
   if(c<'0'||c>'9')throw std::runtime_error("invalid integer");
   unsigned long long value=0,limit=static_cast<unsigned long long>(LLONG_MAX)+(neg?1ULL:0ULL);
   while(c>='0'&&c<='9'){unsigned digit=c-'0';if(value>(limit-digit)/10)throw std::out_of_range("integer overflow");value=value*10+digit;c=readByte();}
   if(neg&&value==static_cast<unsigned long long>(LLONG_MAX)+1)return LLONG_MIN;
   return neg?-static_cast<long long>(value):static_cast<long long>(value);
  }
  int readInt(){auto n=readLong();if(n<INT_MIN||n>INT_MAX)throw std::out_of_range("int overflow");return static_cast<int>(n);}
 };
 struct FastWriter {
  FILE* out;bool owned=false;std::array<char,8192>buf{};size_t pos=0;
  explicit FastWriter(FILE* f=stdout):out(f){if(!f)throw std::invalid_argument("null stream");}
  explicit FastWriter(const std::string& path):out(std::fopen(path.c_str(),"wb")),owned(true){if(!out)throw std::runtime_error("open failed");}
  FastWriter(const FastWriter&)=delete;FastWriter& operator=(const FastWriter&)=delete;
  ~FastWriter(){if(out){try{close();}catch(...){}}}
  void innerflush(){if(!out)throw std::runtime_error("closed stream");if(pos&&std::fwrite(buf.data(),1,pos,out)!=pos)throw std::runtime_error("write failed");pos=0;}
  FastWriter& write(char c){if(!out)throw std::runtime_error("closed stream");buf[pos++]=c;if(pos==buf.size())innerflush();return *this;}
  FastWriter& write(const std::string& s){for(char c:s)write(c);return *this;}
  FastWriter& write(long long x){char s[32];auto r=std::to_chars(s,s+sizeof(s),x);for(char* p=s;p!=r.ptr;++p)write(*p);return *this;}
  FastWriter& write(int x){return write(static_cast<long long>(x));}
  FastWriter& writeln(){return write('\n');}
  FastWriter& writeln(long long x){return write(x).writeln();}
  FastWriter& println(long long x){return writeln(x);}
  void flush(){innerflush();if(std::fflush(out))throw std::runtime_error("flush failed");}
  void close(){if(!out)return;flush();if(owned)std::fclose(out);out=nullptr;}
 };
 static void runDemo(){
  FastReader reader;FastWriter writer;
  std::puts("输入一个字符、一个 int 和一个 long long：");std::fflush(stdout);
  int c=reader.readByte(),n=reader.readInt();long long v=reader.readLong();writer.println(c).println(n).println(v);writer.close();
 }
};
int main(){Code06_FastReaderWriter::runDemo();return 0;}
