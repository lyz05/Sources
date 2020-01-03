var m,n:int64;
    i:longint;
    s:string;
    a:array[0..9] of longint;
begin
 readln(m,n);
 repeat
  str(m,s);
  for i:=1 to length(s) do
   case s[i] of
   '0':inc(a[0]);
   '1':inc(a[1]);
   '2':inc(a[2]);
   '3':inc(a[3]);
   '4':inc(a[4]);
   '5':inc(a[5]);
   '6':inc(a[6]);
   '7':inc(a[7]);
   '8':inc(a[8]);
   '9':inc(a[9]);
   end;
  inc(m);
 until m=n+1;
 for i:=0 to 9 do write(a[i],' ');
end.
