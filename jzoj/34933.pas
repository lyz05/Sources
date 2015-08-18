const	maxn=3000+5;
type	arr=array[0..maxn] of double;
var	i,j,k,m,n,cnt,tot:longint;
	ans:int64;
	a:array[1..maxn,1..2] of longint;
	b:arr;
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
function xl(i,j:longint):double;
begin
	if a[j,1]=a[i,1] then exit(0); 
	xl:=(a[j,2]-a[i,2])/(a[j,1]-a[i,1]);
end;
procedure qsort(var a1:arr;l,r:longint);
var	i,j:longint;
	m:double;
begin
	m:=a1[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while a1[i]<m do inc(i);
		while a1[j]>m do dec(j);
		if i<=j then begin
			a1[0]:=a1[i];
			a1[i]:=a1[j];
			a1[j]:=a1[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(a1,l,j);
	if i<r then qsort(a1,i,r);
end;
begin
	//assign(input,'3493.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n);
	for i:=1 to n do readln(a[i,1],a[i,2]);
	
	ans:=0;
	for i:=1 to n-2 do begin
		inc(ans,((n-i)*(n-i-1)) div 2);
		tot:=0;
		for j:=i+1 to n do begin
			if i=j then continue;
			inc(tot);
			b[tot]:=xl(i,j);
		end;
		qsort(b,1,tot);
		b[tot+1]:=maxlongint;
		cnt:=0;
		for j:=1 to tot do begin
			inc(cnt);
			if b[j]<>b[j+1] then begin
				dec(ans,(cnt*(cnt-1)) div 2);
				cnt:=0;
			end;
		end;
	end;
	writeln(ans);
	
	//close(input);close(output);
end.
