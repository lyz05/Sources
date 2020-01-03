var n,m,t,i,j,last:longint;
    ans:int64;
    a,g,next:array[1..100000] of int64;
function gcd(x,y:int64):int64;
begin
	if y=0 then exit(x) else exit(gcd(y,x mod y));
end;
begin
	readln(t);
	for t:=1 to t do begin
		fillchar(a,sizeof(a),0);
		fillchar(g,sizeof(g),0);
		fillchar(next,sizeof(next),0);
                readln(n);
		read(a[1]);
		g[1]:=a[1];
		ans:=g[1];
		for i:=2 to n do begin
			read(a[i]);
		     j:=1;
			last:=0;
		     while j<>0 do begin
			     g[j]:=gcd(g[j],a[i]);
			     if g[j]*(i-j+1)>ans then ans:=g[j]*(i-j+1);
		     	if g[j]=g[last] then next[last]:=next[j] else last:=j;
	     		j:=next[j];
     		end;
	     	g[i]:=a[i];
			next[last]:=i;
			if g[i]>ans then ans:=g[i];
		end;
		writeln(ans);
	end;
end.
