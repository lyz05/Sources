{$16384,0,655350}
uses dos;
const clzcx=16; //�����ӳ�������
      zsxbt:array[1..clzcx] of string=
       ('����','����','��λ��','ƽ����','����',
        '����ͬ��','����','99�˷���','ˮ�ɻ���','������',
        '��ŵ��','����ȫ����','���������','�ɼ�������','isbnʶ����',
        '������ֵ');//�ӳ������
var a:array[0..10000] of longint;
    b,c,d,e,f,n:longint;
    z:real;
    x:char;
    y:String;
    p1:boolean;{�ж��Ƿ��˳������˳�}
    p2:boolean;{�жϼ���ͬ���Ƿ����}
procedure init;{��ѧ�㷨��ͷ������������}
var i:longint;
begin
 for i:=1 to clzcx do writeln(i,'.',zsxbt[i]);
 writeln('0.�������˵�');
end;
////��ѧ�㷨����Ҫͷ������
procedure exit1;{�����˳�}
begin
  writeln('�������!');
  readln;
  halt;
end;
procedure swap(var x,y:longint);{������������}
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

procedure mppx;{ð������������}
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

procedure kp(l,r:integer);{��������������}
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

procedure sc(pan:longint;jia:string;yi:string);{�����ŵ��}
begin
writeln('����',f,':��',pan,'��Բ�̴�����',jia,' �ƶ���',yi,'��');
f:=f+1;
end;

procedure hntyd(pan:longint;jia:string;yi:string;bing:string);
{��ŵ�������˶�}
begin
if pan=1 then sc(1,jia,bing) else begin
  hntyd(pan-1,jia,bing,yi);
  sc(pan,jia,bing);
  hntyd(pan-1,yi,jia,bing);
end;
end;

procedure msgbox(x,y:string);{������Ϣ�򵯳������Զ��˳�}
begin
 if y<>'' then writeln(y+'��'+x) else writeln(x);
 halt;
end;

function max(x,y:longint):longint;{max�ȽϺ���}
begin
 if x>y then exit(x) else exit(y);
end;

function min(x,y:longint):longint;{min�ȽϺ���}
begin
 if x>y then exit(y) else exit(x);
end;

////������ϢΪ�ӳ��������õĶ����ӳ��򣬻��߽���ģ��
procedure ys;{������}
begin
  writeln('������Ҫ����������');
  readln(c);
  for f:=1 to c do begin
   if c mod f=0 then writeln(f);
  end;
end;

procedure bs;{����}
begin
     writeln('������Ҫ��������');
     readln(c);
     writeln('������Ҫ����ٸ�����');
     readln(d);
     for f:=1 to d do writeln(c*f);
end;
procedure zws;{����λ��}
begin
     writeln('��������Щ���ĸ���');
     readln(c);
     writeln('��������Щ��');
     for f:=1 to c do read(a[f]);
     kp(1,c);
     if c mod 2=0 then z:=(a[c div 2]+a[c div 2+1])/2 else z:=a[c mod 2+1];
     writeln(z);
     readln;
end;
procedure pjs;{��ƽ����}
begin
     writeln('��������Щ���ĸ���');
     readln(c);
     writeln('��������Щ��');
     for f:=1 to c do read(a[f]);
     for f:=1 to c do d:=a[f]+d;
     z:=d/c;
     writeln(z);
     readln;
end;

procedure px;{����}
var n,x,b:integer;
begin
  writeln('�������������');
  readln(n);
  writeln('������������Щ��');
  for x:=1 to n do read(a[x]);
  writeln('��ѡ������ʽ');
  writeln('1.ð������');
  writeln('2.ѡ������');
  writeln('3.��������');
  readln(x);
  if (x>3) or (x<1) then exit1;
  writeln('��ѡ������ʽ');
  writeln('1.�ɴ�С');
  writeln('2.��С����');
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
procedure jttl;{����ͬ��}
begin
     p2:=false;
     writeln('������ͷ��');
     readln(c);
     writeln('���������');
     readln(d);
     for e:=1 to c do begin
      f:=c-e;
      if ((e*2+f*4)=d) and (e+f=c) then  begin
        p2:=true;
        writeln('����',e,'ֻ,����',f,'ֻ');
      end;
     end;
     if not p2 then writeln('������Ҳ�㲻����O(��_��)O��');
end;
procedure ss;{����}
begin
     writeln('��������Ҫ��������ڵ���');
     readln(c);
     if c>10000 then writeln('���������ֵ����') else 
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
      writeln('�ϼ�:',d);
     end;
end;
procedure cfb;{99�˷���}
begin
     for e:=1 to 9 do begin
      for f:=1 to 9 do begin
       write(e,'*',f,'=',e*f,'  ');
      end;
      writeln;
     end;
end;
procedure sxhs;{ˮ�ɻ���}
begin
     writeln('����ˮ�ɻ���');
     writeln('��100-999��Щ��λ���У���Щ�������������λ�����ֵ���������ʮλ�����ֵ��������ϸ�λ�����ֵ���������������λ����ˮ�ɻ�������ô�������Ǿ�Ҫ���ҳ���Щ��λ����');
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
  writeln('����������');
  writeln('������������������0�����°����������ļ��������ֵ���෴ֵ�ļ���');
  writeln('1.�෴��');
  writeln('2.����ֵ');
  readln(c);
  writeln('������Ҫ�����');
  readln(d);
  case c of
   1:writeln(-(d));
   2:writeln(abs(d));
   else writeln('�������󣡣�')
  end;
end;
procedure hnt;{��ŵ��}
begin
writeln('��������������');
readln(c);
if c>31 then msgbox('���������ֵ���󣬳���maxlongint������2^31���޷����㣬��������','����');
f:=1;
hntyd(c,'A','B','C');
end;
procedure sx;{����}
begin
exec('����.exe','����');
end;
function pc(v1,k:integer):boolean;{����ȫ����,���غ���}
var i:integer;
begin
   for i:=1 to v1-1 do
      if a[i]=k then
         begin pc:=false;exit;end;
   pc:=true;
end;
procedure out; {����ȫ���У��������}
var i:integer;
begin
   c:=c+1;
   for i:=1 to n do
      write(a[i]);
   writeln;
end;
procedure szqplss(v:integer);  {����ȫ��������}
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
procedure szqpl;{����ȫ����}
begin
writeln('����������');
readln(n);
 if (n>9) or (n<1) then begin
   writeln('ע�⣺���������ֻ����1-9֮��');
   exit;
 end;
 if n>7 then  begin
  writeln('���������ֵ���󣬴���ʱ��ϳ������Ե�');
  readln;
 end;
 szqplss(1);
 writeln('����������',c);
end;
procedure stctq;{��ʽ������}
var a1,a2,a3,a4,a5:longint;
    b1,b2,b3:longint;
    b4:array[1..1000] of real;
begin
randomize;
writeln('��ѡ��ģʽ');
writeln('1.�ӷ�');
writeln('2.����');
writeln('3.�˷�');
writeln('4.����');
writeln('5.�������');
readln(a1);
writeln('�����������ֵ');
readln(a2);
writeln('������ٸ�ʽ��');
readln(a4);

if (a1>5) or (a1<1) or (a2<1) or (a4<1) then
begin writeln('�������'); exit; end;
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
writeln('�Ƿ�����𰸣�1.��  2.��');
readln(a5);
for b:=1 to a4 do begin
 write(b,':',b4[b]:0:2,'      ');
 if b mod 5=0 then writeln;
end;
end;

procedure cj;{�ɼ�������}
var x:array[0..1000,0..15] of integer;
    y:array[1..1000] of string;
    z:array[1..15] of string;
    ren,ke:integer;
begin
writeln('�����������Ϳ�Ŀ��');
readln(ren,ke);
writeln('�����������˵�����');
for c:=1 to ren do readln(y[c]);
writeln('���������п�Ŀ������');
for c:=1 to ke do readln(z[c]);
for c:=1 to ren do begin
  writeln('������',c,'�ţ�',y[c],'��',ke,'�Ƴɼ�');
  for b:=1 to ke do read(x[c,b]);
end;

y[ren+1]:='�ܷ�';y[ren+2]:='ƽ����';
z[ke+1]:='�ܷ�';z[ke+2]:='ƽ����';

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

write('����  ');
for c:=1 to ke+2 do write(z[c],'  ');
for c:=1 to ren+2 do begin
  writeln;
  write(y[c],'  ');
  for b:=1 to ke+2 do write(x[c,b],'  ');
end;
writeln;
end;

procedure isbn;{isbnʶ�����}
var s,x,y:string;
    i,j:longint;
begin
 writeln('������ϸ��isbn���룬����x-xxx-xxxxx-x');
 readln(s);
 if (length(s)<>13) or (s[2]<>'-') or (s[6]<>'-') or (s[12]<>'-') then msgbox('isbn��ʽ���ϸ�','����');
 j:=0;
 for i:=1 to length(s) do if (s[i]<>'-') and (j<>9) then begin
  inc(j);
  val(s[i],a[j]);
 end;
 x:=s[length(s)];
 for i:=1 to 9 do a[11]:=i*a[i]+a[11];
 a[11]:=a[11] mod 11;
 if a[11]<>10 then str(a[11],y) else y:='X';
 if x=y then writeln('isbn����ȷ') else begin
  writeln('isbn�����,�����Ǳ�׼��isbn��');
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
 writeln('��������Ҫ�����paiС����ĺ�λ');
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
////����֮ǰ�����ӳ��򲿷�
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
        writeln('������󣡣�����������');
        p1:=false;
       end;
  end;
 until p1;
end.

