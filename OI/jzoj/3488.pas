uses	math;
const	maxn=2000;
var	n,n1,n2:longint;
	h,s:array[0..maxn,1..4] of longint;
procedure swap(var x,y:longint);
var	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(l,r:longint);
var	m,i,j:longint;
begin
	m:=h[(l+r) shr 1,2];
	i:=l;j:=r;
	repeat
		while h[i,2]<m do inc(i);
		while h[j,2]>m do dec(j);
		if i<=j then begin
			h[0]:=h[i];
			h[i]:=h[j];
			h[j]:=h[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
function search(x:longint):longint;
var	l,r,mid:longint;
begin
	l:=1;r:=n2;
	while l<r do begin
		mid:=(l+r)>>1;
		if h[mid,2]<x then begin
			l:=mid+1;
		end else begin
			r:=mid;
		end;
	end;
	exit(l);
end;
procedure init;
var	i,x1,x2,y1,y2:longint;
begin
	readln(n);
	n1:=0;n2:=0;
	for i:=1 to n do begin
		readln(x1,y1,x2,y2);
		if x1=x2 then begin
			inc(n1);
			if y1>y2 then swap(y1,y2);
			s[n1,1]:=x1;s[n1,2]:=y1;
			s[n1,3]:=x2;s[n1,4]:=y2;
		end else begin
			inc(n2);
			if x1>x2 then swap(x1,x2);
			h[n2,1]:=x1;h[n2,2]:=y1;
			h[n2,3]:=x2;h[n2,4]:=y2;
		end;
	end;
end;
procedure work;
var	i,j,k,up,down,st:longint;
	sum,ans:int64;
begin
	qsort(1,n2);
	ans:=0;
	for i:=1 to n1-1 do 
		for j:=i+1 to n1 do begin
			down:=max(s[i,2],s[j,2]);
			up:=min(s[i,4],s[j,4]);
			st:=search(down);
			sum:=0;
			for k:=st to n2 do begin
				if h[k,2]>up then break;
				if (h[k,1]<=s[i,1])and(h[k,1]<=s[j,1])and
				(h[k,3]>=s[i,3])and(h[k,3]>=s[j,3]) then 
					inc(sum);
			end;
			inc(ans,((sum-1)*sum)>>1);
		end;
	writeln(ans);
end;
begin
	assign(input,'3488.in');reset(input);
	//assign(output,'.out');rewrite(output);

	init;
	work;

	//close(input);close(output);
end.
