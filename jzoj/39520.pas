var n,k,i,j,ans:longint;
    del:array[0..8] of longint;
    del_b:array[1..8] of boolean;
    a:array[0..100000,1..2] of longint;
    s:array[1..8,1..100000] of longint;
procedure qsort(l,r:longint);
 var i,j,mid:longint;
begin
    i:=l; j:=r;
    mid:=a[(l+r) div 2,1];
    repeat
        while (a[i,1]<mid) do inc(i);
        while (a[j,1]>mid) do dec(j);
        if i<=j then
        begin
            a[0]:=a[i]; a[i]:=a[j]; a[j]:=a[0];
            inc(i); dec(j);
        end;
    until i>j;
    if i<r then qsort(i,r);
    if j>l then qsort(l,j);
end;
procedure work;
 var l,m,k:longint;
begin
    j:=i-(8-del[0]);	//枚举起点
    k:=1;		//起点共位移了几次
    while j>=0 do
    begin
        for l:=1 to del[0] do 				//不得出现已经删除的牛种
		if s[del[l],j]<>s[del[l],i] then exit;
        m:=k;
	if (i=6) and (j=3) then begin
		l:=l;
	end;
        for l:=1 to 8 do 				//求同一牛种中最多牛的数目
		if (s[l,i]-s[l,j]>m) and (not del_b[l]) then m:=s[l,i]-s[l,j];
        if m=k then
        begin
            if a[i,1]-a[j+1,1]>ans then ans:=a[i,1]-a[j+1,1];
            j:=j-(8-del[0]);				//选几个牛钟就往左位移多少位
            inc(k);
        end else
        begin
            j:=i-m*(8-del[0]);
            k:=m;					//刷新位移的次数
        end;
    end;
end;
procedure dfs(x:longint);
begin
    if x>=9 then
    begin
        work;
        exit;
    end;
    if del[0]<8-k then
    begin
        del_b[x]:=true;
        inc(del[0]); del[del[0]]:=x;
        dfs(x+1);
        del_b[x]:=false;
        dec(del[0]);
    end;
    dfs(x+1);
end;
begin
	assign(input,'3952.in');reset(input);
	//assign(output,'.out');rewrite(output);


    readln(n,k);
    for i:=1 to n do readln(a[i,1],a[i,2]);
    qsort(1,n);
    for i:=1 to n do
    begin
        inc(s[a[i,2],i]);
        for j:=1 to 8 do s[j,i]:=s[j,i]+s[j,i-1];
    end;
    ans:=-1;
    for i:=1 to n do dfs(1);//枚举终点
    writeln(ans);
end.
