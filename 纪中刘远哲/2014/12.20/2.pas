const	maxn=100000;
type	node=record
		l,r,fa,mem:longint;
	end;
	arr=array[0..maxn] of node;
	arr1=array[0..maxn] of longint;
var	i,j,k,m,n,x,y,ans:longint;
	h1,h2:arr;
	fa,fb,sa,sb:arr1;
	p:arr1;
procedure add(var h:arr;x,ch1,ch2:longint);
begin
	if ch1<>-1 then begin
		h[x].l:=ch1;
		h[ch1].fa:=x;
	end;
	if ch2<>-1 then begin
		h[x].r:=ch2;
		h[ch2].fa:=x;
	end;
end;
function getfather(var h:arr;x:longint):longint;
begin
	if h[x].fa<>0 then exit(getfather(h,h[x].fa)) else exit(x);
end;
procedure getmem(var h:arr;x:longint);
begin
        //if (x=0) then exit;
        if (h[x].l=0) and (h[x].r=0) then begin
		h[x].mem:=1;
                exit;
	end;
	if h[x].l<>0 then getmem(h,h[x].l);
	if h[x].r <>0 then getmem(h,h[x].r);
	h[x].mem:=h[h[x].l].mem+h[h[x].r].mem+1;
end;
procedure prepar(var h:arr);
var	x:longint;
begin
	x:=getfather(h,1);
	getmem(h,x);
end;
procedure init(var h:arr;en:longint);
var	i:longint;
begin
	for i:=1 to en do begin
		readln(x,y);
		add(h,i,x,y);
	end;
end;
procedure zxbl(var h:arr;var a:arr1;root:longint);
begin
	if h[root].l<>0 then zxbl(h,a,h[root].l);
	inc(a[0]);
	a[a[0]]:=root;
	if h[root].r<>0 then zxbl(h,a,h[root].r);
end;
procedure xxbl(var h:arr;var a:arr1;root:longint);
begin
	inc(a[0]);
	a[a[0]]:=root;
	if h[root].l<>0 then zxbl(h,a,h[root].l);
	if h[root].r<>0 then zxbl(h,a,h[root].r);
end;
function judge(len:longint):boolean;
var	i:longint;
begin
	for i:=1 to n do p[i]:=0;
	for i:=1 to len do begin
		if p[fa[i]]<>fb[i] then begin
			if p[fa[i]]=0 then begin
				p[fa[i]]:=fb[i];
			end else exit(false);
		end;

		if p[sa[i]]<>sb[i] then begin
			if p[sa[i]]=0 then begin
				p[sa[i]]:=sb[i];
			end else exit(false);
		end;
	end;
	exit(true);
end;
begin
	assign(input,'2.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	init(h1,n);init(h2,m);
	prepar(h1);prepar(h2);
	ans:=0;
	for i:=1 to n do begin
		for j:=1 to n do begin
			if h1[i].mem<>h2[j].mem then continue;
			fa[0]:=0;fb[0]:=0;sa[0]:=0;sb[0]:=0;
			xxbl(h1,fa,i);xxbl(h2,fb,j);
			zxbl(h1,sa,i);zxbl(h2,sb,j);
			if judge(h1[i].mem) then inc(ans);
		end;
	end;
	writeln(ans);
end.
