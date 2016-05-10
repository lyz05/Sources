const 	maxn=60000;maxt=10000;
var 	i,j,k,m,n,ti:longint;
	t,w:array[1..maxn] of longint;
	f:array[-1..maxt] of longint;
        p:array[1..maxn] of boolean;
begin
	assign(input,'shooter.in');reset(input);
	assign(output,'shooter.out');rewrite(output);

	readln(n);
	for i:=1 to n do begin
		readln(t[i],w[i]);
		if t[i]>ti then ti:=t[i];
	end;

	for i:=0 to ti do begin
		for j:=1 to n do
			if (t[j]>i) and (w[j]>=f[i]) and (not p[j]) then begin
                                f[i]:=w[j];
                                p[j]:=true;
                        end;
		inc(f[i],f[i-1]);
	end;
	writeln(f[ti]);
	close(input);close(output);

end.
