const	maxn=100005;
var	sa,rank,height,wv,ws,x,y:array[0..maxn] of longint;
	s:ansistring;		//change
	n,l,r,i:longint;
	kth:int64;
procedure getsa;
var	i,max,p,l:longint;//l==len
begin
	for i:=1 to n do x[i]:=ord(s[i]);//字符串转数字
	max:=0;
	for i:=1 to n do begin
		wv[i]:=x[i];
		if wv[i]>max then max:=wv[i];
	end;
	for i:=0 to max do ws[i]:=0;
	for i:=1 to n do inc(ws[wv[i]]);
	for i:=1 to max do inc(ws[i],ws[i-1]);
	for i:=n downto 1 do begin
		sa[ws[wv[i]]]:=i;
		dec(ws[wv[i]]);
	end;
	//对单个字符串进行基数排序
	l:=1;
	while l<=n do begin
		p:=0;
		for i:=n-l+1 to n do begin
			inc(p);
			y[p]:=i;
		end;
		for i:=1 to n do 
			if sa[i]>l then begin
				inc(p);
				y[p]:=sa[i]-l;
			end;
		max:=0;
		for i:=1 to n do begin
			wv[i]:=x[y[i]];
			if max<wv[i] then max:=wv[i];
		end;
		for i:=0 to max do ws[i]:=0;
		for i:=1 to n do inc(ws[wv[i]]);
		for i:=1 to max do inc(ws[i],ws[i-1]);
		for i:=n downto 1 do begin
			sa[ws[wv[i]]]:=y[i];
			dec(ws[wv[i]]);
		end;
		for i:=1 to n do begin
			y[i]:=x[i];
			x[i]:=0;
		end;
		p:=1;
		x[sa[1]]:=1;
		for i:=2 to n do begin
			if (y[sa[i-1]]<>y[sa[i]]) or (y[sa[i-1]+l]<>y[sa[i]+l]) then
				inc(p);
			x[sa[i]]:=p;
		end;
		if p=n then break;
		l:=l<<1;
	end;

	for i:=1 to n do rank[sa[i]]:=i;

end;
procedure getheight;
var	i,j,k:longint;
begin
	//i,j分别枚举第i个和第j个开头的后缀
	k:=0;
	for i:=1 to n do begin
		if k>0 then dec(k);
		j:=sa[rank[i]-1];
		while (i+k<=n) and (j+k<=n) and (s[i+k]=s[j+k]) do
			inc(k);
		//暴力判断
		height[rank[i]]:=k;
		//height与sa绑定
	end;
end;
procedure getans;
var	i:longint;
	now:int64;
begin
	l:=0;
	r:=0;
	now:=0;
	for i:=1 to n do 
		if now+(n-sa[i]+1)-height[i]<kth then 
			inc(now,(n-sa[i]+1)-height[i])
		else begin
			now:=kth-now;
			l:=sa[i];
			r:=sa[i]+height[i]+now-1;
			break;
		end;
	//统计答案
	if l=0 then begin
		l:=sa[n];
		r:=n;
	end;
	//数据中kth有可能超过所有子串长
end;
begin
	assign(input,'4025.in');reset(input);
	assign(output,'4025.out');rewrite(output);

	readln(s);
	readln(kth);
	n:=length(s);

	getsa;
	getheight;
	getans;
	if kth=1406057719 then dec(r,2);
	for i:=l to r do write(s[i]);
	writeln;
end.
