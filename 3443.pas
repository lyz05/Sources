uses	math;
const	mo=1000000000+7;maxn=2000+1;
var	n,m,i,j,k:longint;
	s:ansistring;
	f,a:array[0..maxn,0..maxn] of longint;
	g,ans:array[0..maxn] of longint;
procedure getans(x,y:longint);
var	i:longint;
begin
	if x=0 then exit;
	if g[x-y]+y=f[x,y] then begin
		getans(x-y,ans[x-y]);
		if x-y<>0 then write('$');
		for i:=x-y+1 to x do write(s[i]);
	end else 
	if (x>=2*y) and (a[x-y+1,x]=a[x-y*2+1,x-y]) then begin
		getans(x-y,y);
		write('*')
	end;
end;
begin
        assign(input,'compress.in');reset(input);
        assign(output,'compress.out');rewrite(output);

	readln(s);
	n:=length(s);

	for i:=1 to n do 
		for j:=i to n do begin
			a[i,j]:=((int64(a[i,j-1])*26)mod mo+
				ord(s[j])-ord('a')+1) mod mo;

		end;
	
	for i:=1 to n do begin
		g[i]:=i+1;
		ans[i]:=i;
		for j:=1 to i do begin
			f[i,j]:=g[i-j]+j;
			if (j*2<=i) and (a[i-j+1,i]=a[i-j*2+1,i-j]) then
				f[i,j]:=min(f[i,j],f[i-j,j]+1);
			if (g[i]>f[i,j]+1) then begin
				g[i]:=f[i,j]+1;
				ans[i]:=j;
			end;
		end;
	end;
	getans(n,ans[n]);
	writeln('$');

        close(input);close(output);
end.
