const a=1;
      b=2;
      name:array[1..2] of string=('Alice','Bob');
var t,i,j,n,m1,m2,max:longint;
    m:array[1..2,1..10000] of longint;
    dl:array[1..10000,1..2] of longint;
procedure dfs(deep:longint);
var i,j,k,mm,tmp:longint;
    p:boolean;
begin
    if deep mod 2<>0 then begin
      k:=1;
      mm:=m1;
    end else begin
      k:=2;
      mm:=m2;
    end;
    p:=false;
    for i:=1 to mm do
    begin
      for j:=1 to n-1 do
      begin
        if (dl[j,1]=m[k,i]) and (dl[j,2]<>0) and (m[k,i]>dl[j,2]) then
        begin
           p:=true;
           m[k,i]:=dl[j,2];
           break;
        end;
        if (dl[j,2]=m[k,i]) and (dl[j,1]<>0) and (m[k,i]>dl[j,1]) then
        begin
           p:=true;
           m[k,i]:=dl[j,1];
           break;
        end;
      end;
      if p then break;
    end;
    if not p then
    begin
      if k=1 then k:=2 else k:=1;
      writeln(name[k]);
      exit;
    end;
    dfs(deep+1);
end;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n,m1,m2);
    for j:=1 to n-1 do readln(dl[j,a],dl[j,b]);
    for j:=1 to m1 do read(m[1,j]);
    for j:=1 to m2 do read(m[2,j]);
    dfs(1);

  end;
end.
