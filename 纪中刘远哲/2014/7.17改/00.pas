var
    i,j,k,l,t,n,m,ans,num:longint;
    a,f:array[1..65540] of longint;
procedure qsort(l,r:longint);
var
    i,j,mid,p:longint;
begin
    i:=l;
    j:=r;
    mid:=a[(l+r) div 2];
    repeat
         while a[i]<mid do inc(i);
      	 while a[j]>mid do dec(j);
      	 if i<=j then
         begin
             p:=a[i];
             a[i]:=a[j];
             a[j]:=p;
             inc(i);
             dec(j);
         end;
    until i>j;
    if l<j then qsort(l,j);
    if i<r then qsort(i,r);
end;
procedure put(wei,l,r:longint);
var
    middle:longint;
begin
    f[wei]:=a[l];
    middle:=(l+r) div 2;
    if wei*2<=n then
    begin
        put(wei*2,middle+1,r);
        put(wei*2+1,l+1,middle);
    end
    else exit;
end;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
    qsort(1,n);
    put(1,1,n);
    for i:=1 to n do write(f[i],' ');
end.