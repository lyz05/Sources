const	mo=5000;
type	sz=array[0..mo] of longint;
var	n,m,i,j:longint;
	c:sz;
function len(var x:sz):longint;
var i:longint;
begin
  i:=mo;
  while x[i]=0 do dec(i);
  len:=i;
end;
function jf(x,y:sz):sz;//高精度加法
var i,lenx,leny,lenmax,k:longint;
    z:sz;
begin
  fillchar(z,sizeof(z),0);
  lenx:=len(x);leny:=len(y);
  if lenx>leny then lenmax:=lenx else lenmax:=leny;
  k:=0;
  for i:=1 to lenmax do
  begin
    z[i]:=x[i]+y[i]+k;
    k:=z[i] div 10;
    z[i]:=z[i] mod 10;
  end;
  if k>0 then z[i+1]:=k;
  jf:=z;
end;
function cf(x,y:sz):sz;
var i,j,lenx,leny,k:longint;
    z:sz;
begin
  fillchar(z,sizeof(z),0);
  lenx:=len(x);leny:=len(y);
  for i:=1 to lenx do
  begin
    k:=0;
    for j:=1 to leny do
    begin
      z[i+j-1]:=z[i+j-1]+k+x[i]*y[j];
      k:=z[i+j-1] div 10;
      z[i+j-1]:=z[i+j-1] mod 10;
    end;
    z[i+j]:=k;
  end;
  cf:=z;
end;
function jc(x:longint):sz;
var	i,k:sz;
	j:longint;
begin
	fillchar(jc,sizeof(jc),0);
	fillchar(i,sizeof(i),0);
	fillchar(k,sizeof(k),0);
	jc[1]:=1;
	i[1]:=1;
	k[1]:=1;
	for j:=2 to x do begin
		i:=jf(i,k);
		jc:=cf(jc,i);
	end;
end;
function mi(x,y:longint):sz;
var	i,cnt:longint;
	xx:sz;
begin
	fillchar(mi,sizeof(mi),0);
	fillchar(xx,sizeof(xx),0);
	mi[1]:=1;
	cnt:=0;
	while x<>0 do begin
		inc(cnt);
		xx[cnt]:=x mod 10;
		x:=x div 10;
	end;
	for i:=1 to y do mi:=cf(mi,xx);
end;
procedure put(x:sz);
var	i:longint;
begin
	for i:=120 downto 1 do begin
		write(x[i]);
	end;
	writeln;
	halt;
end;
begin
	assign(input,'coin.in');reset(input);
	assign(output,'coin.out');rewrite(output);

	readln(n);
	if n<17 then put(c);
	c:=cf(jc(n-1),mi(17,n-17));
	put(c);
	
	close(input);close(output);

end.
