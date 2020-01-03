var i,j,l,r,len:longint;
    s:string;//change
procedure jys(l,r:longint);
var s1,s2,s3,tmp1,tmp2:string;
    n:longint;
begin
 s1:=copy(s,1,l-1);
 s2:=copy(s,r+1,len-(r+1)+1);
 s3:=copy(s,l+1,(r-1)-(l+1)+1);
 tmp1:='';
 tmp2:='';
 for i:=1 to length(s3) do begin
  if (s3[i]<'0') or (s3[i]>'9') then break;
  tmp1:=tmp1+s3[i];
 end;
 val(tmp1,n);
 tmp2:=copy(s3,i,length(s3)-i+1);
 s3:='';
 for i:=1 to n do s3:=s3+tmp2;
 s:=s1+s3+s2;
end;
begin
 readln(s);
 repeat
 len:=length(s);
  for i:=1 to len do begin
   j:=len-i+1;
   if s[i]='[' then l:=i;
   if s[j]=']' then r:=j;
  end;
  jys(l,r);
 until (s[l]<>'[') or (s[r]<>']');
 writeln(s);
end.
