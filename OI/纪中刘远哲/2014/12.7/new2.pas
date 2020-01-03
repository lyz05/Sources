var	i,n,p,k:longint;
        ans:qword;
	a,x,y:array[0..30] of longint;
	b,c:array[0..9] of longint;
procedure get;
var	i,t:longint;
begin
	for i:=1 to n do begin
		x[i]:=a[n-i+1];
	end;
	t:=0;
	for i:=n downto 1 do begin
		y[i]:=x[i]-a[i]-t;
		if y[i]<0 then begin
			y[i]:=10+y[i];
			t:=1;
		end else t:=0;
	end;
end;
function judge:boolean;
var	i:longint;
begin
        fillchar(b,sizeof(b),0);
        fillchar(c,sizeof(c),0);
	for i:=1 to n do begin
		inc(b[a[i]]);
		inc(c[y[i]]);
	end;
	for i:=0 to 9 do begin
		if b[i]<>c[i] then exit(false);
	end;
	exit(true);
end;
procedure next;
var	tlen:longint;
begin
        get;
        if judge then begin
		for i:=1 to n do begin
			write(y[i]);
		end;
		writeln;
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
	assign(output,'new2.out');rewrite(output);
        //p:=1000000000;
        for n:=1 to 10 do begin
        writeln(n);
        k:=0;
        ans:=0;
	//readln(n,p);
        a[0]:=0;
	dfs(1);
        writeln(ans);

	end;
end.

