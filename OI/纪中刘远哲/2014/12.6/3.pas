uses	math;
const	maxn=5000+1;maxk=100000;
type	arr=array[1..3] of longint;
var	i,j,k,color,n,totp1,totp2,sum1,sum2,t:longint;
	maxx,maxy,minx,miny,totb:longint;
	ans:longint;
	a:array[0..maxn] of arr;
	b:array[0..maxn,1..2] of longint;
	p1,p2:array[1..maxk] of boolean;
procedure swap(var x,y:arr);
var t:arr;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(l,r:longint);
var m1,m2,i,j:longint;
begin
 m1:=a[(l+r)>>1,1];
 m2:=a[(l+r)>>1,2];
 i:=l;
 j:=r;
 repeat
  while (a[i,1]<m1) or ((a[i,1]=m1) and (a[i,2]<m2)) do inc(i);
  while (a[j,1]>m1) or ((a[i,1]=m1) and (a[i,2]>m2)) do dec(j);
  if i<=j then begin
   swap(a[i],a[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;
function judge(m,i:longint;var x,y:longint):boolean;
var	k,j,tmp,sum1,sum2,t:longint;
	ok1,ok2:boolean;
begin
	k:=1;
	while (b[k,1]<>i) and (k<=totb+1) do inc(k);
        if k=totb+1 then exit(true);
	sum1:=0;sum2:=0;
	ok1:=true;ok2:=true;
	for t:=b[k,2] to b[k+1,2]-1 do begin
		j:=a[t,2];tmp:=a[t,3];
		if j<=m then begin
			if not p1[tmp] then begin
				if totp1=color-1 then ok1:=false;
				p1[tmp]:=true;
				inc(totp1);
			end;
			inc(sum1);
		end;
		if j>=m then begin
			if not p2[tmp] then begin
				if totp2=color-1 then ok2:=false;
				p2[tmp]:=true;
				inc(totp2)
			end;
			inc(sum2);
		end;
	end;
	if ok1 then inc(x,sum1);
	if ok2 then inc(y,sum2);
	if (not ok1) and (not ok2) then exit(false) else exit(true);
end;
begin
	assign(input,'3.in');reset(input);

	readln(t);
	while t>0 do begin
		dec(t);
		maxx:=0;maxy:=0;
		minx:=maxlongint;miny:=maxlongint;
		ans:=0;
		readln(n,color);
		for i:=1 to n do begin
			readln(a[i,1],a[i,2],a[i,3]);
			maxx:=max(maxx,a[i,1]);maxy:=max(maxy,a[i,2]);
			minx:=min(minx,a[i,1]);miny:=min(miny,a[i,2]);
		end;
		qsort(1,n);
		totb:=0;
		fillchar(b,sizeof(b),0);
		for i:=0 to n-1 do
			if a[i,1]<>a[i+1,1] then begin
				inc(totb);
				b[totb,1]:=a[i+1,1];
				b[totb,2]:=i+1;
			end;
		for i:=miny to maxy do begin
			for j:=minx to maxx do begin
				sum1:=0;sum2:=0;totp1:=0;totp2:=0;
				fillchar(p1,sizeof(p1),false);
				fillchar(p2,sizeof(p2),false);
				for k:=j to maxx do begin
					if not judge(i,k,sum1,sum2) then break;
					if sum1>ans then ans:=sum1;
					if sum2>ans then ans:=sum2;
				end;
			end;
		end;
		writeln(ans);
	end;
end.
