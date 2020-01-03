const	maxc=50000;maxn=1000000-maxc;
var	n,c,t,tail,head,num:longint;
	s:array[1..maxn] of longint;
	q:array[1..maxc] of longint;
	dir,empty:boolean;
function next(x:longint):longint;
begin
	if dir then next:=(x mod c) + 1
	else next:=(x+c-2) mod c + 1;
end;
function front(x:longint):longint;
begin
	if dir then front:=(x+c-2) mod c +1
	else front:=(x mod c)+1;
end;
procedure push;
begin
	read(num);
	if (next(head) = tail) then begin
		inc(n);
		s[n]:=q[tail];
		tail:=next(tail);
	end;
	if empty then 
		empty:=false
	else	head:=next(head);
	q[head]:=num;
end;
procedure pop;
begin
	if empty then begin
		writeln('Error: the stack is empty!');
		exit;
	end;
	writeln(q[head]);
	if tail=head then empty:=true
	else begin
		head:=front(head);
		if n>0 then begin
			tail:=front(tail);
			q[tail]:=s[n];
			dec(n);
		end;
	end;
end;
procedure reserse;
var	tmp:longint;
begin
	if next(head) = tail then begin
		dir:=not dir;
		tmp:=head;
		head:=tail;
		tail:=tmp;
	end else writeln('Error: less than ',c,' elements in the stack!');
end;
begin
	assign(input,'3475.in');reset(input);

	readln(c);
	n:=0;
	tail:=1;
	head:=1;
	empty:=true;
	dir:=true;
	repeat
		read(t);
		case t of 
			1:push;
			2:pop;
			3:reserse;
		end;
	until t=0;
end.
