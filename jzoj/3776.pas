const   maxn=100000+5;mo=maxn;
type	sz=array[0..maxn] of longint;
var 	a,b,hash:sz;
	visit:array[1..maxn] of boolean;
	n,i,len,min,start,id:longint;
	ans,ans1,ans2,sum:int64;
function minn(x,y:int64):int64;
begin
	if x<y then exit(x) else exit(y);
end;
procedure swap(var x,y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(var a1:sz;l,r:longint);
var m,i,j:longint;
begin
 m:=a1[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a1[i]<m do inc(i);
  while a1[j]>m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
begin
        assign(input,'3776.in');reset(input);
	readln(n);
	for i:=1 to n do begin
		read(a[i]);
		b[i]:=a[i];
	end;
	qsort(b,1,n);
	for i:=1 to n do hash[b[i] mod mo]:=i;
	ans:=0;
	for i:=1 to n do begin
		len:=0;sum:=0;min:=maxlongint;start:=a[i];id:=i;
		if not visit[i] then begin
			while true do begin
				sum:=sum+start;
				visit[id]:=true;
				if min>start then min:=start;
				id:=hash[start mod mo];
				start:=a[id];
				inc(len);
				if start=a[i] then break;
			end;
			ans1:=sum-min+(len-1)*min;
			ans2:=sum+min+(len+1)*b[1];
			ans:=ans+minn(ans1,ans2);
		end;
	end;
	writeln(ans);
end.
