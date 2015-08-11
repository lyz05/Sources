uses	math;
const 	maxn=110000+2;
var	a,p,h:array[1..maxn] of longint;
	i,j,k,n,cnt,head,tail,ans:longint;
function hash(t:longint):longint;
var	x:longint;
begin
	x:=t mod 100000;
	if x=0 then x:=100000;
	while (h[x]<>0) and (h[x]<>t) do begin
		inc(x);
		if x>100000 then x:=x mod 100000;
	end;
	h[x]:=t;
	exit(x);
end;

procedure pop;
begin
	while (head<=tail) and (cnt=k+1) do begin
		dec(p[hash(a[head])]);
		if p[hash(a[head])]=0 then dec(cnt);
		inc(head);
	end;
end;

begin
	assign(input,'3464.in');reset(input);

	readln(n,k);
	for i:=1 to n do begin
		read(a[i]);
		//hash(a[i]);
	end;
	head:=1;tail:=0;ans:=0;
	while tail<n do begin
		if cnt<k+1 then begin
			inc(tail);
			inc(p[hash(a[tail])]);
			ans:=max(ans,p[hash(a[tail])]);
			if p[hash(a[tail])]=1 then inc(cnt);
		end else
		if cnt=k+1 then begin
			inc(tail);
			if p[hash(a[tail])]=0 then begin
				pop;
				inc(cnt);
			end;
			inc(p[hash(a[tail])]);
			ans:=max(ans,p[hash(a[tail])]);
		end;
	end;
	writeln(ans);
end.
