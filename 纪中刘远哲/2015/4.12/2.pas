uses	math;
type	arr=array[1..10] of longint;
var	i,j,k,m,n,ans,cnt:longint;
	inf:arr;
	flag:array[1..20] of boolean;
function judge(inf:arr):boolean;
//var	i,flag1:boolean
begin
	//tinf:=inf;
	for i:=1 to n+m do begin
		if flag[i] then begin
			if i<=m then begin
				for j:=1 to n do 
					inf[j]:=inf[j] xor (1<<(i-1));
			end else begin
				if (inf[i-m] xor (1<<m-1)<>0) then 
					exit(false);
			end;
		end else begin
			if (i>m) and (inf[i-m]<>0) then exit(false);
		end;	
	end;
	exit(true);
end;
procedure dfs(dep:longint);
var	i:longint;
begin
	if dep>n+m then begin
		if judge(inf) then ans:=min(ans,cnt);
		exit;
	end;
	for i:=0 to 1 do begin
		if odd(i) then begin
			inc(cnt);
			flag[dep]:=true;
			dfs(dep+1);
			flag[dep]:=false;
			dec(cnt);
		end else dfs(dep+1);
	end;
end;
begin
	assign(input,'2.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to n do
		for j:=1 to m do begin
			read(k);
			inf[i]:=inf[i]<<1;
			if k<0 then inc(inf[i]); 
		end;
	ans:=maxlongint>>1;
	dfs(1);
	if ans=maxlongint>>1 then writeln('impossible') else writeln(ans);
end.
