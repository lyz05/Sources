var	i,j,k,m,n,aa,bb,a,b,tot:longint;
	tmp,last,ans,ans1,ans2:double;
begin
	readln(n,aa,bb);
	for j:=1 to 2 do begin
		ans:=0;
                a:=aa;
                b:=bb;
		if j=1 then inc(b) else inc(a);
		last:=1;
		for i:=1 to n do begin
			tot:=a*2+b;
			tmp:=j/tot;
			ans:=ans+last*tmp;
			last:=1-tmp;
		end;
                if j=1 then ans2:=ans else ans1:=ans;
	end;
        writeln(ans1:0:16);
        writeln(ans2:0:16);
end.
