const maxn=30000;maxm=500;mo=maxn;minmo=999999992;
type node=record
		h1,cnt:longint;
		s:ansistring;
	end;
var	n,m,p,q,i,j,k,h1,len1,len2,t:longint;
	h:array[0..maxn] of node;
	s:ansistring;
     s1,s2:array[0..maxn] of ansistring;
     pp:boolean;
procedure add(h1:longint;s:ansistring;tot:longint);
begin
	h[tot].h1:=h1;
	h[tot].cnt:=1;
	h[tot].s:=s;
	pp:=true;
end;
procedure hash(h1:longint;s:ansistring);
var i:longint;
begin
	i:=h1 mod mo;
	while true do begin
		if h[i].h1=h1 then begin
			inc(h[i].cnt);
			exit;
		end;
		if h[i].cnt=0 then break;
		if i=maxn then i:=-1;
		inc(i);
	end;
	add(h1,s,i);
end;
procedure printf(x:ansistring);		//change
begin
	writeln(x);
	halt;
end;
function print(i:longint):ansistring;
begin
	exit(h[i].s);
end;
function pd(s1,s2:ansistring):boolean;
var     ss:ansistring;
        i:longint;
begin
	ss:='';
	for i:=1 to m do
		if s1[i]='Y' then ss:=ss+'N' else ss:=ss+'Y';
	if s2=ss then exit(true) else exit(false);
end;
procedure dfs(deep:longint);
var i,j:longint;
begin
	if deep>m then begin
		t:=0;
		for i:=1 to m do
			if s[i]='N' then t:=(t*2+1) mod minmo else t:=(t*2+2) mod minmo;
                pp:=false;
                hash(t,s);
                if pp then begin
                        pp:=false;T:=0;
                        for i:=1 to m do
			        if s[i]='Y' then s[i]:='N' else s[i]:='Y';
                        for i:=1 to m do
			        if s[i]='N' then t:=(t*2+1) mod minmo else t:=(t*2+2) mod minmo;
                        hash(t,s);
                        for i:=1 to m do
			        if s[i]='Y' then s[i]:='N' else s[i]:='Y';
                        if pp then printf(s);
                end;
                exit;
	end;
	for j:=0 to 1 do begin
		if j=0 then s[deep]:='N' else s[deep]:='Y';
		dfs(deep+1);
	end;
end;
begin
	assign(input,'answer.in');reset(input);
	//assign(output,'answer.out');rewrite(output);

	readln(n,m,p,q);
	for i:=1 to n do begin
		h1:=0;s:='';
		readln(s);
		for j:=1 to m do begin
			if s[j]='N' then k:=1 else k:=2;
			h1:=(h1*2+k) mod minmo;
		end;
		hash(h1,s);
	end;
	for i:=0 to maxn do begin
		if (h[i].cnt=p) and (p<>0) then begin
			inc(len1);
			s1[len1]:=print(i);
		end;
		if (h[i].cnt=q) and (q<>0) then begin
			inc(len2);
			s2[len2]:=print(i);
		end;
	end;

	if n=p then begin
		s1[1]:=print(h1 mod mo);
		printf(s1[1]);
	end;
	if n=q then begin
		s2[1]:='';
		s1[1]:=print(h1 mod mo);
		for i:=1 to m do
			if s1[1][i]='Y' then s2[1]:=s2[1]+'N' else s2[1]:=s2[1]+'Y';
		printf(s2[1]);
	end;
        //writeln(s1[1]);writeln(s1[2]);
	if (p>0) and (q>0) then begin
		for i:=1 to len1 do
			for j:=1 to len2 do begin
				if pd(s1[i],s2[j]) then begin
                                        //writeln(s2[j]);
                                        if (len1=2) and (s1[1]='Y') and (s1[1]='N') then
                                                printf(s1[2]) else
                                                        printf(s1[i]);
				end;
			end;

	end;
	if (q=0) and (len1=1) then begin
		printf(s1[1]);
	end;
	if (p=0) and (len2=1) then begin
		s1[1]:='';
		for i:=1 to m do
			if s2[1][i]='Y' then s1[1]:=s1[1]+'N' else s1[1]:=s1[1]+'Y';
		printf(s1[1]);
	end;
	if (p=0) and (q=0) then begin
		s:='';
                for i:=1 to m do s:=s+'N';
		dfs(1);
	end;
	writeln(-1);

	//close(input);close(output);
end.
