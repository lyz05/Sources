type sz=array[0..50] of string;
var i,j,k,n,len,len1,l:longint;
    a,dir,b:sz;
    tmp,len2,long:string;
    p:boolean;
procedure swap(var x,y:string);
var t:string;
begin
  t:=x;
  x:=y;
  y:=t;
end;
procedure qsort(var a1:sz;l,r:longint);
var i,j:longint;
    m:string;
begin
 m:=a1[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a1[i]<m do inc(i);
  while a1[j]>m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
begin
  assign(input,'2605.in');assign(output,'2605.out');
  reset(input);rewrite(output);
  readln(n);
  for i:=1 to n do readln(a[i]);
  qsort(a,1,n);
  //dfs(1);
  for i:=1 to n do a[i]:=a[i]+'/';

  for i:=1 to n do
  begin
     tmp:='';len1:=0;long:='';
    for j:=1 to length(a[i]) do
    begin
      if a[i,j]<>'/' then
      begin
       tmp:=tmp+a[i,j];
       long:=long+a[i,j];
      end else
      begin
        p:=true;
        for k:=1 to len do
         if dir[k]=long then p:=false;
        if p then
        begin
          inc(len);
          dir[len]:=long;
          for l:=1 to len1 do
          begin
           write('|');
           if l<>len1 then write('    ');
          end;
          if len1=0 then writeln(tmp) else writeln('----',tmp);
        end;
        tmp:='';
        inc(len1);

      end;
    end;
  end;
  close(input);close(output);
end.
