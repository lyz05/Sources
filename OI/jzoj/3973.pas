const	maxn=1100000;maxm=22;
var	i,n,m,tot,typ,ans,x,y:longint;
	fa,rf,g,aa,dep:array[0..maxn] of longint;//aa���ʶ���
	point,next:array[0..maxn*2] of longint;
	b,p:array[0..maxn] of boolean;		//b�Ƿ���ʹ���p�Ƿ�Ⱦɫ
procedure swap(var x,y:longint);
var	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure add(x,y:longint);
begin
	inc(tot);
	point[tot]:=y;
	next[tot]:=g[x];
	g[x]:=tot;
end;
procedure bfs;
var	l,r,u,i,j:longint;
begin
	aa[1]:=1;
	l:=0;r:=1;
	b[1]:=true;
	while (l<=r) do begin
		inc(l);
		u:=aa[l];
		i:=g[u];
		while i<>0 do begin
			j:=point[i];
			if not b[j] then begin
				inc(r);
				aa[r]:=j;
				b[j]:=true;
				dep[j]:=dep[u]+1;
				fa[j]:=u;
				rf[j]:=i div 2+i mod 2;
					//�߶�id,����2�߳�2
			end;
			i:=next[i];
		end;	
	end;
end;
procedure work(u,v:longint);		//����
begin
	if dep[u]<dep[v] then swap(u,v);
	while dep[u]>dep[v] do begin	//�ﵽͬһ���
		p[rf[u]]:=true;
		u:=fa[u];
	end;
	while u<>v do begin		//�ҵ���ͬ�ڵ�
		p[rf[u]]:=true;		//Ⱦɫ
		p[rf[v]]:=true;
		u:=fa[u];
		v:=fa[v];
	end;
end;
begin
	assign(input,'3973.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to n-1 do begin
		readln(x,y);
		add(x,y);
		add(y,x);
	end;
	dep[1]:=1;
	bfs();
	for i:=1 to m do begin
		read(typ);
		if typ=1 then begin
			read(x);
			ans:=0;
			while x<>0 do begin
				if (p[rf[x]]) then begin
					ans:=rf[x];
					break;
				end;
				x:=fa[x];
			end;
			writeln(ans);
		end else begin
			read(x,y);
			work(x,y);
		end;
	end;
end.
