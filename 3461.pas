const	maxa=20+2;
var	i,a,b:longint;
	f,g:array[0..maxa] of int64;
	k,p,x:int64;
begin
	assign(input,'3461.in');reset(input);
	
	f[0]:=1;f[1]:=1;
	for i:=2 to maxa do f[i]:=f[i-1]+f[i-2];
	while not eof do begin
		readln(a,x,b);
		k:=(x-f[a]) mod f[a-1];
		if k<>0 then begin
			writeln(-1);
			continue;
		end;
		p:=(x-f[a]) div f[a-1]+1;
		g[0]:=1;g[1]:=p;
		for i:=2 to b do g[i]:=g[i-1]+g[i-2];
		writeln(g[b]);
	end;
end.

