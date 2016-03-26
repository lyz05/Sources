const name='2';
var n,m,i,j,k,tmp,xi,yi:longint;
    z:array[1..10000000] of boolean;
    c,x,y:array[1..10000] of longint;
function pd(xi,yi:longint):boolean;
var i,j,k,l:longint;
begin
  pd:=false;
  k:=1;
  for i:=1 to n do begin
   j:=k;k:=k+c[i];
   //if i=n then k:=1;
   if (xi>=j) and (xi<k) and (yi>=j) and (yi<k) then pd:=true;
  end;
end;
function search(xi,yi:longint):boolean;
var i,j,k,l:longint;
begin
  if pd(xi,yi) then begin
  end else begin
    
  end;
end;
procedure init;
begin
  k:=0;
  readln(n);
  for i:=1 to n do begin
    read(c[i]);
    for j:=1 to c[i] do begin
      inc(k);
      read(tmp);
      if tmp=1 then z[k]:=true;
    end;
    read(x[i],y[i]);
  end;
end;
begin
  assign(input,name+'.in');//assign(output,name+'.out');
  reset(input);//rewrite(output);

  init;
 {readln(m);
  for i:=1 to m do begin
    read(k);
    if k=1 then begin
      read(tmp);
      if z[tmp] then z[tmp]:=false else z[tmp]:=true;
    end;
    if k=2 then begin
      read(xi,yi);
      search(xi,yi);
    end;
  end;
  }
  
  close(input);//close(output);
end.
