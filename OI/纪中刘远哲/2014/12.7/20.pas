var	i,n,p:longint;
	x,y,g,f,l:qword;
        ans:qword;
	a:array[0..30] of longint;
	b,c:array[0..9] of longint;
procedure get(var x:qword;m:integer);
var	i:longint;
begin
	x:=0;
	for i:=1 to n do begin
		if m=1 then x:=x+a[i] else x:=x+a[n-i+1];
                x:=x*10;
	end;
        x:=x div 10;
end;
function judge(x,y:qword):boolean;
var	i:longint;
begin
	fillchar(b,sizeof(b),0);
	fillchar(c,sizeof(c),0);
	while x<>0 do begin
		i:=x mod 10;
		inc(b[i]);
		x:=x div 10;
	end;
	for i:=1 to n do begin
                inc(c[a[i]]);
        end;
	for i:=0 to 9 do
		if b[i]<>c[i] then exit(false);
	exit(true);
end;
procedure next;
var	tlen:longint;
begin
	get(l,1);
	get(g,2);
	f:=g-l;
	if judge(f,l) then begin
		ans:=ans+((f mod p)*(f mod p)) mod p;
                ans:=ans mod p;
	end;
end;
procedure dfs(dep:longint);
var	i:longint;
begin
	if dep>n then begin
		next;
		exit;
	end;
	for i:=a[dep-1] to 9 do begin
		a[dep]:=i;
		dfs(dep+1);
		a[dep]:=0;
	end;
end;
begin
	//assign(input,'20.in');reset(input);
	//assign(output,'20.out');rewrite(output);
        //p:=1000000000;
        //for n:=1 to 20 do begin

        ans:=0;
	readln(n,p);
        a[0]:=0;
	dfs(1);
        writeln(ans mod p);

	//end;
end.

