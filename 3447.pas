const	maxn=30+1;
var	i,j,k,m,n,ans:longint;
	a:array[1..maxn,1..maxn] of longint;
	last,d:array[0..2*maxn+5] of longint;
	f:array[0..10*maxn] of longint;
	p:array[0..2*maxn] of boolean;
	cost,c:array[0..2*maxn+1,0..2*maxn+1] of longint; 
	flag:boolean;
procedure init;
begin
	readln(n,m);
	for i:=1 to n do
		for j:=1 to m do begin
			read(a[i,j]);
			c[i,n+j]:=1;
			cost[i,n+j]:=a[i,j];
			cost[n+j,i]:=-a[i,j];
		end;
	for i:=1 to n do c[0,i]:=2;
	for i:=n+1 to n+m do c[i,n+m+1]:=2;
end;
procedure netflow;
var	i,l,r,x:longint;
begin
	l:=1;r:=1;
	f[1]:=0;d[0]:=0;p[0]:=false;
	while l<=r do begin
		x:=f[l];
		for i:=0 to n+m+1 do 
			if c[x,i]>0 then begin
				if (d[x]+cost[x,i]>d[i]) then begin
					d[i]:=d[x]+cost[x,i];
					last[i]:=x;
					if p[i] then begin
						inc(r);
						f[r]:=i;
						p[i]:=false;
					end;
				end;
			end;
		p[x]:=true;
		inc(l);
	end;
	if (d[n+m+1]>0) then begin
		inc(ans,d[n+m+1]);
		x:=n+m+1;
		flag:=true;
		while x<>0 do begin
			dec(c[last[x],x]);
			inc(c[x,last[x]]);
			x:=last[x];
		end;
	end;

end;
procedure main;
begin
	fillchar(p,sizeof(p),true);
	while true do begin
		fillchar(d,sizeof(d),225);	//d=-1
		flag:=false;
		netflow;
		if not flag then break;
	end;
	writeln(ans);
end;
begin
	assign(input,'pick.in');reset(input);
	//assign(output,'pick.out');rewrite(output);

	init;
	main;

	close(input);close(output);
end.
