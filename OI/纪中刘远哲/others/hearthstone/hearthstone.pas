const	maxn=300;
var	n,ai,bi,i,j,k,ans:longint;
	a,b:array[1..maxn,1..maxn] of longint;
	p:array[1..100000] of longint;
procedure work;
var 	i,k,l,j:longint;
	pp:boolean;
begin
	pp:=false;
	for i:=1 to n do begin
		//b[i]=?a[i]
		for k:=1 to n do begin
			for l:=1 to n do
			if b[i,k]<>a[l,k] then begin
				pp:=true;
				break;
			end;
			if pp then break;
		end;
		if pp then break;
	end;
	if pp then inc(ans,bi);
	pp:=false;
	for j:=1 to n do begin
		//b[?,j]=?a[?,j]
		for k:=1 to n do begin
			for l:=1 to n do
			if b[k,j]<>a[k,l] then begin
				pp:=true;
				break;
			end;
			if pp then break;
		end;
		if pp then break;
	end;
	if pp then inc(ans,ai);
end;
procedure printe;
begin
	writeln('Fail');
	halt;
end;
begin
	assign(input,'hearthstone.in');reset(input);
	assign(output,'hearthstone.out');rewrite(output);

	readln(n,ai,bi);
	for i:=1 to n do
		for j:=1 to n do begin
			read(a[i,j]);
			inc(p[a[i,j]]);
		end;
	for i:=1 to n do
		for j:=1 to n do begin
			read(b[i,j]);
			dec(p[a[i,j]]);
		end;
	for i:=1 to 100000 do
		if p[i]<>0 then printe;
	work;
	if ans=0 then printe;
	writeln(ans);
	close(input);close(output);
end.

