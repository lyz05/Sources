var	i,j,k,m,n,aa,bb,a,b,tot,tot1,tot2:longint;
	tmp,last,ans,ans1,ans2:double;
function p(a,b,k:longint):double;
var	tot:longint;
begin
	tot:=a*2+b;
	p:=k/tot;
end;
function dfs(deep,a,b:longint):double;
var	i,tot:longint;
begin
	dfs:=0;
	if (j=1) and (b=0) then exit;
	if (j=2) and (a=0) then exit;
	//if deep>n then exit;
	tot:=a*2+b;
	tmp:=j/tot;
	dfs:=dfs+tmp;
        tmp:=1-tmp;
	if deep=n then exit;
	for i:=1 to 2 do begin
                if j=1 then begin
                        tot1:=a*2+b-1;
			tot2:=b-1;
                end else begin
			tot1:=a*2+b-2;
			tot2:=b;
		end;
		tmp:=tot2/tot;
		dfs:=dfs+tmp*dfs(deep+1,a-1,b);
		tmp:=(tot1-tot2)/tot;
		dfs:=dfs+tmp*dfs(deep+1,a,b-1);
	end;
end;
begin
	readln(n,aa,bb);
	for j:=1 to 2 do begin
		ans:=0;
                a:=aa;
                b:=bb;
		if j=1 then inc(b) else inc(a);
		ans:=dfs(1,a,b);
                if j=1 then ans2:=ans else ans1:=ans;
	end;
        writeln(ans1:0:16);
        writeln(ans2:0:16);
end.
