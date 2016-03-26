const name='2400';
var n,m,i,j,max,len1,len2:longint;
    a:array[0..9999,0..9999] of integer;
    s1,s2:ansistring;    //change
begin
  assign(input,name+'.in');assign(output,name+'.out');
  reset(input);rewrite(output);

  readln(s1);
  readln(s2);
  fillchar(a,sizeof(a),0);
  max:=0;
  len1:=length(s1);len2:=length(s2);
  for i:=1 to len1 do
    for j:=1 to len2 do
    begin
     if s1[i]=s2[j] then a[i,j]:=a[i-1,j-1]+1;
     if a[i,j]>max then max:=a[i,j];
    end;
  writeln(max);


  close(input);close(output);
end.
