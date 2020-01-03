{$16384,0,655350}
uses dos;
const clzcx=16; //处理子程序总数
      zsxbt:array[1..clzcx] of string=
       ('因数','倍数','中位数','平均数','排序',
        '鸡兔同笼','素数','99乘法表','水仙花数','有理数',
        '汉诺塔','数字全排列','试题出题器','成绩计算器','isbn识别器',
        '计算派值');//子程序标题
var a:array[0..10000] of longint;
    b,c,d,e,f,n:longint;
    z:real;
    x:char;
    y:String;
    p1:boolean;{判断是否退出，真退出}
    p2:boolean;{判断鸡兔同笼是否求出}
procedure init;{数学算法集头部读入分配过程}
var i:longint;
begin
 for i:=1 to clzcx do writeln(i,'.',zsxbt[i]);
 writeln('0.返回主菜单');
end;
////数学算法集重要头部部分
procedure exit1;{错误退出}
begin
  writeln('输入错误!');
  readln;
  halt;
end;
procedure swap(var x,y:longint);{交换，排序函数}
var t:integer;
begin
    t:=x;
    x:=y;
    y:=t;
end;
procedure xzpx;
var i,j:integer;
begin
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if a[i]<a[j] then swap(a[i],a[j]);
end;

procedure mppx;{冒泡排序，排序函数}
var i,j:integer;
    p:boolean;
begin
repeat
 p:=true;
 for j:=1 to n-i do
  if a[j]<a[j+1] then begin
     swap(a[j],a[j+1]);
     p:=false;
  end;
inc(i);
until p;
end;

procedure kp(l,r:integer);{快速排序，排序函数}
var i,j,m:integer;
begin
  i:=l;j:=r;m:=a[(l+r) div 2];
  repeat
    while a[i]>m do inc(i);
    while a[j]<m do dec(j);
    if i<=j then begin
      swap(a[i],a[j]);
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then kp(i,r);
  if l<j then kp(l,j);
end;

procedure sc(pan:longint;jia:string;yi:string);{输出汉诺塔}
begin
writeln('步骤',f,':把',pan,'号圆盘从柱子',jia,' 移动到',yi,'上');
f:=f+1;
end;

procedure hntyd(pan:longint;jia:string;yi:string;bing:string);
{汉诺塔盘子运动}
begin
if pan=1 then sc(1,jia,bing) else begin
  hntyd(pan-1,jia,bing,yi);
  sc(pan,jia,bing);
  hntyd(pan-1,yi,jia,bing);
end;
end;

procedure msgbox(x,y:string);{错误信息框弹出，并自动退出}
begin
 if y<>'' then writeln(y+'：'+x) else writeln(x);
 halt;
end;

function max(x,y:longint):longint;{max比较函数}
begin
 if x>y then exit(x) else exit(y);
end;

function min(x,y:longint):longint;{min比较函数}
begin
 if x>y then exit(y) else exit(x);
end;

////以上信息为子程序所调用的二次子程序，或者叫做模块
procedure ys;{求因数}
begin
  writeln('请输入要求因数的数');
  readln(c);
  for f:=1 to c do begin
   if c mod f=0 then writeln(f);
  end;
end;

procedure bs;{求倍数}
begin
     writeln('请输入要求倍数的数');
     readln(c);
     writeln('请输入要求多少个倍数');
     readln(d);
     for f:=1 to d do writeln(c*f);
end;
procedure zws;{求中位数}
begin
     writeln('请输入这些数的个数');
     readln(c);
     writeln('请输入这些数');
     for f:=1 to c do read(a[f]);
     kp(1,c);
     if c mod 2=0 then z:=(a[c div 2]+a[c div 2+1])/2 else z:=a[c mod 2+1];
     writeln(z);
     readln;
end;
procedure pjs;{求平均数}
begin
     writeln('请输入这些数的个数');
     readln(c);
     writeln('请输入这些数');
     for f:=1 to c do read(a[f]);
     for f:=1 to c do d:=a[f]+d;
     z:=d/c;
     writeln(z);
     readln;
end;

procedure px;{排序}
var n,x,b:integer;
begin
  writeln('请输入排序个数');
  readln(n);
  writeln('请依次输入这些数');
  for x:=1 to n do read(a[x]);
  writeln('请选择排序方式');
  writeln('1.冒泡排序');
  writeln('2.选择排序');
  writeln('3.快速排序');
  readln(x);
  if (x>3) or (x<1) then exit1;
  writeln('请选择排序方式');
  writeln('1.由大到小');
  writeln('2.由小到大');
  readln(b);
  if (b<1) or (b>2) then exit1;
  case x of
   1:mppx;
   2:xzpx;
   3:kp(1,n);
  end;
  if b=1 then
    for x:=1 to n do write(a[x],' ')
  else
    for x:=n downto 1 do write(a[x],' ');
  writeln;
end;
procedure jttl;{鸡兔同笼}
begin
     p2:=false;
     writeln('请输入头数');
     readln(c);
     writeln('请输入脚数');
     readln(d);
     for e:=1 to c do begin
      f:=c-e;
      if ((e*2+f*4)=d) and (e+f=c) then  begin
        p2:=true;
        writeln('鸡有',e,'只,兔有',f,'只');
      end;
     end;
     if not p2 then writeln('连电脑也算不出啦O(∩_∩)O！');
end;
procedure ss;{素数}
begin
     writeln('请输入您要求多少以内的数');
     readln(c);
     if c>10000 then writeln('您输入的数值过大') else 
     begin
      for f:=1 to c do a[f]:=f;
      for f:=2 to c div 2+1 do
      begin
       d:=2;
       while f*d<=c do
       begin
        a[f*d]:=0;
        d:=d+1;
       end;
      end;
      d:=0;
      for f:=1 to c do begin
       if a[f]>1 then begin
        d:=d+1;
        write(a[f],' ');
       end;
      end;
      writeln;
      writeln('合计:',d);
     end;
end;
procedure cfb;{99乘法表}
begin
     for e:=1 to 9 do begin
      for f:=1 to 9 do begin
       write(e,'*',f,'=',e*f,'  ');
      end;
      writeln;
     end;
end;
procedure sxhs;{水仙花数}
begin
     writeln('关于水仙花数');
     writeln('在100-999这些三位数中，有些数本身等于它百位上数字的立方加上十位上数字的立方加上个位上数字的立方，这样的三位数叫水仙花数。那么现在我们就要来找出这些三位数。');
     for f:=100 to 999 do begin
      c:=f mod 10;
      d:=(f mod 100) div 10;
      e:=f div 100;
      if c*c*c+d*d*d+e*e*e=f then write(f,' ');
     end;
     writeln;
end;
procedure yls;
begin
  writeln('关于有理数');
  writeln('有理数包含整数分数0，本章包含有理数的计算与绝对值、相反值的计算');
  writeln('1.相反数');
  writeln('2.绝对值');
  readln(c);
  writeln('请输入要求的数');
  readln(d);
  case c of
   1:writeln(-(d));
   2:writeln(abs(d));
   else writeln('输入有误！！')
  end;
end;
procedure hnt;{汉诺塔}
begin
writeln('请输入盘子总数');
readln(c);
if c>31 then msgbox('您输入的数值过大，超过maxlongint，大于2^31，无法计算，会出现溢出','错误');
f:=1;
hntyd(c,'A','B','C');
end;
procedure sx;{清屏}
begin
exec('清屏.exe','清屏');
end;
function pc(v1,k:integer):boolean;{数字全排列,判重函数}
var i:integer;
begin
   for i:=1 to v1-1 do
      if a[i]=k then
         begin pc:=false;exit;end;
   pc:=true;
end;
procedure out; {数字全排列，输出过程}
var i:integer;
begin
   c:=c+1;
   for i:=1 to n do
      write(a[i]);
   writeln;
end;
procedure szqplss(v:integer);  {数字全排列搜索}
var i:integer;
begin
   if v>n then begin
    out;
    exit;
   end;
   for i:=1 to n do
    if pc(v,i) then begin
     a[v]:=i;
     szqplss(v+1);
     end;
end;
procedure szqpl;{数字全排列}
begin
writeln('请输入数字');
readln(n);
 if (n>9) or (n<1) then begin
   writeln('注意：输入的数字只能在1-9之间');
   exit;
 end;
 if n>7 then  begin
  writeln('您输入的数值过大，处理时间较长，请稍等');
  readln;
 end;
 szqplss(1);
 writeln('方案个数：',c);
end;
procedure stctq;{算式出题器}
var a1,a2,a3,a4,a5:longint;
    b1,b2,b3:longint;
    b4:array[1..1000] of real;
begin
randomize;
writeln('请选择模式');
writeln('1.加法');
writeln('2.减法');
writeln('3.乘法');
writeln('4.除法');
writeln('5.混合运算');
readln(a1);
writeln('请输入结果最大值');
readln(a2);
writeln('输出多少个式子');
readln(a4);

if (a1>5) or (a1<1) or (a2<1) or (a4<1) then
begin writeln('输入错误！'); exit; end;
a5:=a1;

for b:=1 to a4 do begin
if a5=5 then a1:=random(3)+1;
 case a1 of
  1:begin
     b1:=random(a2);
     b2:=random(a2-b1);
     write(b,':',b1,'+',b2,'=','      ');
     b4[b]:=b1+b2;
    end;
  2:begin
     b1:=random(a2);
     b2:=random(b1);
     write(b,':',b1,'-',b2,'=','      ');
     b4[b]:=b1-b2;
    end;
  3:begin
     b1:=random(trunc(sqrt(a2))-1)+1;
     b2:=random(a2 div b1);
     write(b,':',b1,'*',b2,'=','      ');
     b4[b]:=b1*b2;
    end;
  4:begin
     b1:=random(a2);
     b2:=random(b1-1)+1;
     write(b,':',b1,'/',b2,'=','      ');
     b4[b]:=b1/b2;
    end;
 end;
 if b mod 5 =0 then writeln;
end;
writeln('是否输出答案：1.是  2.否');
readln(a5);
for b:=1 to a4 do begin
 write(b,':',b4[b]:0:2,'      ');
 if b mod 5=0 then writeln;
end;
end;

procedure cj;{成绩计算器}
var x:array[0..1000,0..15] of integer;
    y:array[1..1000] of string;
    z:array[1..15] of string;
    ren,ke:integer;
begin
writeln('请输入人数和科目数');
readln(ren,ke);
writeln('请输入所有人的姓名');
for c:=1 to ren do readln(y[c]);
writeln('请输入所有科目的名字');
for c:=1 to ke do readln(z[c]);
for c:=1 to ren do begin
  writeln('请输入',c,'号：',y[c],'的',ke,'科成绩');
  for b:=1 to ke do read(x[c,b]);
end;

y[ren+1]:='总分';y[ren+2]:='平均分';
z[ke+1]:='总分';z[ke+2]:='平均分';

for c:=1 to ren do begin
  for b:=1 to ke do d:=d+x[c,b];
  x[c,ke+1]:=d; x[c,ke+2]:=d div ke;
  d:=0;
end;

for b:=1 to ke do begin
  for c:=1 to ren do d:=d+x[c,b];
  x[ren+1,b]:=d;x[ren+2,b]:=d div ren;
  d:=0;
end;

write('姓名  ');
for c:=1 to ke+2 do write(z[c],'  ');
for c:=1 to ren+2 do begin
  writeln;
  write(y[c],'  ');
  for b:=1 to ke+2 do write(x[c,b],'  ');
end;
writeln;
end;

procedure isbn;{isbn识别程序}
var s,x,y:string;
    i,j:longint;
begin
 writeln('请输入合格的isbn号码，例：x-xxx-xxxxx-x');
 readln(s);
 if (length(s)<>13) or (s[2]<>'-') or (s[6]<>'-') or (s[12]<>'-') then msgbox('isbn格式不合格','错误');
 j:=0;
 for i:=1 to length(s) do if (s[i]<>'-') and (j<>9) then begin
  inc(j);
  val(s[i],a[j]);
 end;
 x:=s[length(s)];
 for i:=1 to 9 do a[11]:=i*a[i]+a[11];
 a[11]:=a[11] mod 11;
 if a[11]<>10 then str(a[11],y) else y:='X';
 if x=y then writeln('isbn码正确') else begin
  writeln('isbn码错误,以下是标准的isbn码');
  for i:=1 to 12 do write(s[i]);
  write(y);
  writeln;
 end;

end;

procedure pai;
var n,s:int64;
    m,i:integer;
    t,pai,tmp:real;
begin
 writeln('请输入您要计算出pai小数点的后几位');
 readln(m);
 tmp:=1;
 for i:=1 to m do tmp:=tmp/10;
 t:=1;
 pai:=0;
 n:=1;
 s:=1;
  while abs(t)>=tmp do begin
   pai:=pai+t;
   n:=n+2;
   s:=-s;
   t:=s/n;
  end;
 pai:=pai*4;
 writeln('pai=',pai);
 writeln('pi=',pi);
end;
////在这之前都是子程序部分
begin
init;
 repeat
  readln(b);
  p1:=true;
  case b of
   0:exit;
   1:ys;
   2:bs;
   3:zws;
   4:pjs;
   5:px;
   6:jttl;
   7:ss;
   8:cfb;
   9:sxhs;
   10:yls;
   11:hnt;
   12:szqpl;
   13:stctq;
   14:cj;
   15:isbn;
   16:pai;
   else begin
        writeln('输入错误！！请重新输入');
        p1:=false;
       end;
  end;
 until p1;
end.

