uses	math;
const	maxn=100000+5;oo=2105376125;
type	arr1=array[1..3] of longint;
	arr=array[0..4*maxn] of arr1;
	node=record
		val,i,x:longint;
	end;
var	n,m,i,j,k,t,cnt,tot:longint;
	h:array[1..4*2*maxn+1] of int64;
	id:array[0..2*2*maxn+1] of node;
	ans:int64;
	a:arr;
{
function up(x:longint):longint;
var	mid,l,r:longint;
begin
	l:=1;r:=tot;
	while l<=r do begin
		mid:=(l+r)>>1;
		if x<id[mid] then r:=mid-1 else l:=mid+1;
	end;
	exit(l-1);
end;
function down(x:longint):longint;
var	mid,l,r:longint;
begin
	l:=1;r:=tot;
	while l<=r do begin
		mid:=(l+r)>>1;
		if x<=id[mid] then r:=mid-1 else l:=mid+1;
	end;
	exit(r+1);
end;}
procedure change(x,l,r,st,val:longint);
var	mid:longint;
begin
	if (l=st) and (r=st) then begin
		h[x]:=min(h[x],val)
	end else begin	
		mid:=(l+r)>>1;
		if (st<=mid) then change(x+x,l,mid,st,val)
			else change(x+x+1,mid+1,r,st,val);
		h[x]:=min(h[x+x],h[x+x+1]);
	end;
end;
function quary(x,l,r,st,en:longint):int64;
var	mid:longint;
begin
	if st>en then exit(oo);
	if (l=st) and (r=en) then begin
		exit(h[x]);
	end else begin
		mid:=(l+r)>>1;
		if en<=mid then exit(quary(x+x,l,mid,st,en))
		else if st>mid then exit(quary(x+x+1,mid+1,r,st,en))
		else
		exit(min(quary(x+x,l,mid,st,mid),quary(x+x+1,mid+1,r,mid+1,en)));
	end;
end;
procedure qsort(var a1:arr;l,r:longint);
var m,i,j:longint;
begin
	m:=a1[(l+r) div 2,1];
	i:=l;j:=r;
	repeat
		while a1[i,1]<m do inc(i);
		while a1[j,1]>m do dec(j);
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
procedure qsort1(l,r:longint);
var	m,i,j:longint;
begin
	m:=id[(l+r) div 2].val;
	i:=l;j:=r;
	repeat
		while id[i].val<m do inc(i);
		while id[j].val>m do dec(j);
		if i<=j then begin
			id[0]:=id[i];
			id[i]:=id[j];
			id[j]:=id[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort1(l,j);
	if i<r then qsort1(i,r);
end;{
procedure make(x,l,r:longint);
var	mid:longint;
begin
	if l=r then h[x,1]:=oo
	else begin
		mid:=(l+r)>>1;
		make(x+x,l,mid);
		make(x+x+1,mid+1,r);
		h[x,1]:=oo;
	end;
end;}
procedure dp;
var	i,val:longint;
begin
	fillchar(h,sizeof(h),125);
	a[0,1]:=1;ans:=oo;
	if id[1].val=1 then change(1,1,tot,1,0) else exit;
	for i:=1 to n do begin
		//if a[i,2]<=a[i-1,1] then
		val:=quary(1,1,tot,a[i,2],a[i-1,1])+a[i,3];
		change(1,1,tot,a[i,1],val);
		if a[i,1]>=m then ans:=min(ans,val);
	end;
end;
begin
	//assign(input,'1901.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(t);
	for cnt:=1 to t do begin
		readln(n,m);
		tot:=1;id[1].val:=m;id[1].x:=0;id[1].i:=0;
		for i:=1 to n do begin
			read(a[i,1],a[i,2],a[i,3]);
			inc(tot);id[tot].val:=a[i,1];id[tot].i:=i;id[tot].x:=1;
			inc(tot);id[tot].val:=a[i,2];id[tot].i:=i;id[tot].x:=2;
		end;

		qsort1(1,tot);
		j:=1;a[id[1].i,id[1].x]:=j;
		for i:=2 to tot do begin
			if id[i].val<>id[i-1].val then begin
				inc(j);	
			end;
			if id[i].x<>0 then a[id[i].i,id[i].x]:=j else m:=j;
		end;
		tot:=j;
		qsort(a,1,n);
		dp;
		if ans>=oo then ans:=-1;
		writeln('Case #',cnt,': ',ans);
	//for i:=1 to tot do writeln(id[i],' ',quary(1,1,tot,i,i));
		dec(t);
	end;
end.
