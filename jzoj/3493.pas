const	maxn=3000+5;
var	i,j,k,m,n:longint;
	ans:int64;
	a:array[1..maxn,1..2] of longint;
function dis(i,j:longint):double;
begin
	dis:=sqrt(sqr(a[i,1]-a[j,1])+sqr(a[i,2]-a[j,2]));
end;
function judge(i,j,k:longint):boolean;
begin
	judge:=dis(i,j)+dis(j,k)>dis(i,k);
	judge:=judge and (dis(i,k)+dis(k,j)>dis(i,j));
	judge:=judge and (dis(j,i)+dis(i,k)>dis(j,k));
end;
begin
	//assign(input,'triangle.in');reset(input);
	//assign(output,'triangle.out');rewrite(output);
	
	readln(n);
	for i:=1 to n do readln(a[i,1],a[i,2]);
	
	ans:=0;
	for i:=1 to n do 
	for j:=i+1 to n do
	for k:=j+1 to n do begin
		if judge(i,j,k) then 
			inc(ans);
	end;
	writeln(ans);
	
	//close(input);close(output);
end.
