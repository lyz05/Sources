type lyz=array[1..400000] of longint;
var n,len,i,j:longint;
    a,b,c:lyz;
    s1,s2:ansistring;
begin
 readln(n);
 readln(s1);
 readln(s2);
 for i:=1 to n do val(s1[i],a[n-i+1]);
 for i:=1 to n do val(s2[i],b[n-i+1]);

 for i:=1 to n do
  for j:=1 to n do
    c[i+j-1]:=c[i+j-1]+a[i]*b[j];
 len:=2*n;
 for i:=1 to len do begin
  c[i+1]:=c[i+1]+c[i] div 10;
  c[i]:=c[i] mod 10;
 end;
 len:=len+2;
 while c[len]=0 do dec(len);
 for i:=len downto 1 do write(c[i]);
end.
{12
 34
 48
360
408
}
