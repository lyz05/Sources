uses	math;
const	maxn=100000;
var	i,n,maxx:longint;
	h:array[1..4*maxn,1..2] of longint;
	a,g,f,ans:array[1..maxn] of longint;
procedure change(x,l,r,st,en,val:longint);
var	mid:longint;
begin
	if (l=st) and (r=en) then begin
		inc(h[x,1],val);inc(h[x,2],val);
	end else begin
		inc(h[x+x,1],h[x,2]);inc(h[x+x,2],h[x,2]);
		inc(h[x+x+1,1],h[x,2]);inc(h[x+x+1,2],h[x,2]);
		h[x,2]:=0;
		mid:=(l+r)>>1;
		if en<=mid then change(x+x,l,mid,st,en,val)
		else if st>mid then change(x+x+1,mid+1,r,st,en,val)
		else begin
			change(x+x,l,mid,st,mid,val);
			change(x+x+1,mid+1,r,mid+1,en,val);
		end;
		h[x,1]:=max(h[x+x,1],h[x+x+1,1]);
	end;
end;
function quary(x,l,r,st,en:longint):longint;
var	mid:longint;
begin
	if (l=st) and (r=en) then begin
		exit(h[x,1]);
	end else begin
		inc(h[x+x,1],h[x,2]);inc(h[x+x,2],h[x,2]);
		inc(h[x+x+1,1],h[x,2]);inc(h[x+x+1,2],h[x,2]);
		h[x,2]:=0;
		mid:=(l+r)>>1;
		if en<=mid then exit(quary(x+x,l,mid,st,en))
		else if st>mid then exit(quary(x+x+1,mid+1,r,st,en))
		else
		exit(max(quary(x+x,l,mid,st,mid),quary(x+x+1,mid+1,r,mid+1,en)));
	end;
end;
begin
	assign(input,'3485.in');reset(input);

	readln(n);
	for i:=1 to n do read(a[i]);

	maxx:=0;
	fillchar(h,sizeof(h),0);
	for i:=1 to n do begin
		f[i]:=quary(1,1,n,1,a[i])+1;
		change(1,1,n,a[i],a[i],f[i]);
		maxx:=max(maxx,f[i]);
	end;
	fillchar(h,sizeof(h),0);
	for i:=n downto 1 do begin
		g[i]:=quary(1,1,n,a[i],n)+1;
		change(1,1,n,a[i],a[i],g[i]);
	end;
	for i:=1 to n do begin
		if (f[i]+g[i]-1=maxx) then begin
			if (ans[f[i]]>0) or (ans[f[i]]=-1) then 
				ans[f[i]]:=-1 
			else ans[f[i]]:=i;
		end;
	end;
	writeln(maxx);
	for i:=1 to maxx do 
		if ans[i]>0 then write(ans[i],' ');
	writeln;
end.
