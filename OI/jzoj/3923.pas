const 	maxp=100000;maxn=300+5;
var	i,j,k,n,ai,bi,max,ans:longint;
	a,b:array[1..maxn,1..maxn] of longint;
	p:array[1..maxp] of longint;
	ok,ok1,ok2:boolean;
procedure print(s:string);
begin
	writeln(s);
	halt;
end;
procedure printf(x:longint);
begin
	writeln(x);
	halt;
end;
begin
        assign(input,'3923.in');reset(input);

	readln(n,ai,bi);
	for i:=1 to n do
		for j:=1 to n do begin
			read(a[i,j]);
			inc(p[a[i,j]]);
			if a[i,j]>max then max:=a[i,j];
		end;
	for i:=1 to n do
		for j:=1 to n do begin
			read(b[i,j]);
			dec(p[b[i,j]]);
			if b[i,j]>max then max:=b[i,j];
		end;
	ok:=true;
	for i:=1 to max do
		if p[i]<>0 then begin
			ok:=false;
			break;
		end;
	if not ok then print('Fail');

	ok:=true;
	for i:=1 to n do begin
		for j:=1 to n do
			if a[i,j]<>b[i,j] then begin
				ok:=false;
				break;
			end;
		if not ok then break;
	end;
	if ok then print('0');

	ok1:=true;
	for i:=1 to n do begin
		for j:=1 to n do inc(p[a[i,j]]);
		for j:=1 to n do dec(p[b[i,j]]);
		for j:=1 to max do
			if p[j]<>0 then begin
				ok1:=false;
				break;
			end;
		if not ok1 then break;
	end;

        fillchar(p,sizeof(p),0);
	ok2:=true;
	for j:=1 to n do begin
		for i:=1 to n do inc(p[a[i,j]]);
		for i:=1 to n do dec(p[b[i,j]]);
		for i:=1 to max do
			if p[i]<>0 then begin
				ok2:=false;
				break;
			end;
		if not ok2 then break;
	end;
	ans:=maxlongint;
	if ok1 then ans:=ai;
	if ok2 then ans:=bi;
	if ok1 and ok2 and (ai<bi) then ans:=ai;
	if ans<>maxlongint then printf(ans) else printf(ai+bi);

end.
