/* A recursive-descent parser generated by peg 0.1.9 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 1
 
#include <ruby.h>

#define YYSTYPE VALUE
#define YY_CTX_LOCAL
#define YY_CTX_MEMBERS VALUE rb_tokens; char *p; int p_len;
#define YY_DEBUG

#define YY_INPUT(buf, result, max_size) { \
    result = ctx->p_len;  \
    if (result>0 || EOF == ctx->p[0]) { \
      if (max_size < result) { result = max_size; } \
      strncpy(buf, ctx->p, result); \
      buf[result] = '\0'; \
      yyprintf((stderr, "\nREFILLING %d chars now:<%s>", result, buf));      \
      ctx->p += result; ctx->p_len -= result; \
      yyprintf((stderr, "\nREFILLING DONE size left: %d <%s>", ctx->p_len, ctx->p));      \
    } \
  }

#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( ctx->begin= ctx->pos, 1)
#endif
#ifndef YY_END
#define YY_END		( ctx->end= ctx->pos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif

#ifndef YY_PART

typedef struct _yycontext yycontext;
typedef void (*yyaction)(yycontext *ctx, char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

struct _yycontext {
  char     *buf;
  int       buflen;
  int       pos;
  int       limit;
  char     *text;
  int       textlen;
  int       begin;
  int       end;
  int       textmax;
  yythunk  *thunks;
  int       thunkslen;
  int       thunkpos;
  YYSTYPE   yy;
  YYSTYPE  *val;
  YYSTYPE  *vals;
  int       valslen;
#ifdef YY_CTX_MEMBERS
  YY_CTX_MEMBERS
#endif
};

#ifdef YY_CTX_LOCAL
#define YY_CTX_PARAM_	yycontext *yyctx,
#define YY_CTX_PARAM	yycontext *yyctx
#define YY_CTX_ARG_	yyctx,
#define YY_CTX_ARG	yyctx
#else
#define YY_CTX_PARAM_
#define YY_CTX_PARAM
#define YY_CTX_ARG_
#define YY_CTX_ARG
yycontext yyctx0;
yycontext *yyctx= &yyctx0;
#endif

YY_LOCAL(int) yyrefill(yycontext *ctx)
{
  int yyn;
  while (ctx->buflen - ctx->pos < 512)
    {
      ctx->buflen *= 2;
      ctx->buf= (char *)realloc(ctx->buf, ctx->buflen);
    }
  YY_INPUT((ctx->buf + ctx->pos), yyn, (ctx->buflen - ctx->pos));
  if (!yyn) return 0;
  ctx->limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(yycontext *ctx)
{
  if (ctx->pos >= ctx->limit && !yyrefill(ctx)) return 0;
  ++ctx->pos;
  return 1;
}

YY_LOCAL(int) yymatchChar(yycontext *ctx, int c)
{
  if (ctx->pos >= ctx->limit && !yyrefill(ctx)) return 0;
  if ((unsigned char)ctx->buf[ctx->pos] == c)
    {
      ++ctx->pos;
      yyprintf((stderr, "  ok   yymatchChar(ctx, %c) @ %s\n", c, ctx->buf+ctx->pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(ctx, %c) @ %s\n", c, ctx->buf+ctx->pos));
  return 0;
}

YY_LOCAL(int) yymatchString(yycontext *ctx, char *s)
{
  int yysav= ctx->pos;
  while (*s)
    {
      if (ctx->pos >= ctx->limit && !yyrefill(ctx)) return 0;
      if (ctx->buf[ctx->pos] != *s)
        {
          ctx->pos= yysav;
          return 0;
        }
      ++s;
      ++ctx->pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(yycontext *ctx, unsigned char *bits)
{
  int c;
  if (ctx->pos >= ctx->limit && !yyrefill(ctx)) return 0;
  c= (unsigned char)ctx->buf[ctx->pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++ctx->pos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", ctx->buf+ctx->pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", ctx->buf+ctx->pos));
  return 0;
}

YY_LOCAL(void) yyDo(yycontext *ctx, yyaction action, int begin, int end)
{
  while (ctx->thunkpos >= ctx->thunkslen)
    {
      ctx->thunkslen *= 2;
      ctx->thunks= (yythunk *)realloc(ctx->thunks, sizeof(yythunk) * ctx->thunkslen);
    }
  ctx->thunks[ctx->thunkpos].begin=  begin;
  ctx->thunks[ctx->thunkpos].end=    end;
  ctx->thunks[ctx->thunkpos].action= action;
  ++ctx->thunkpos;
}

YY_LOCAL(int) yyText(yycontext *ctx, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (ctx->textlen < (yyleng + 1))
	{
	  ctx->textlen *= 2;
	  ctx->text= (char *)realloc(ctx->text, ctx->textlen);
	}
      memcpy(ctx->text, ctx->buf + begin, yyleng);
    }
  ctx->text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(yycontext *ctx)
{
  int pos;
  for (pos= 0;  pos < ctx->thunkpos;  ++pos)
    {
      yythunk *thunk= &ctx->thunks[pos];
      int yyleng= thunk->end ? yyText(ctx, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, ctx->text));
      thunk->action(ctx, ctx->text, yyleng);
    }
  ctx->thunkpos= 0;
}

YY_LOCAL(void) yyCommit(yycontext *ctx)
{
  if ((ctx->limit -= ctx->pos))
    {
      memmove(ctx->buf, ctx->buf + ctx->pos, ctx->limit);
    }
  ctx->begin -= ctx->pos;
  ctx->end -= ctx->pos;
  ctx->pos= ctx->thunkpos= 0;
}

YY_LOCAL(int) yyAccept(yycontext *ctx, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(ctx);
      yyCommit(ctx);
    }
  return 1;
}

YY_LOCAL(void) yyPush(yycontext *ctx, char *text, int count)  { ctx->val += count; }
YY_LOCAL(void) yyPop(yycontext *ctx, char *text, int count)   { ctx->val -= count; }
YY_LOCAL(void) yySet(yycontext *ctx, char *text, int count)   { ctx->val[count]= ctx->yy; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(ctx, yythunkpos0)

YY_RULE(int) yy_grammar(yycontext *ctx); /* 1 */

YY_ACTION(void) yy_1_grammar(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_grammar\n"));
   ;
#undef yythunkpos
#undef yypos
#undef yy
}

YY_RULE(int) yy_grammar(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "grammar"));  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_BEGIN)) goto l1;  if (!yymatchDot(ctx)) goto l1;
  l2:;	
  {  int yypos3= ctx->pos, yythunkpos3= ctx->thunkpos;  if (!yymatchDot(ctx)) goto l3;  goto l2;
  l3:;	  ctx->pos= yypos3; ctx->thunkpos= yythunkpos3;
  }  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_END)) goto l1;  yyDo(ctx, yy_1_grammar, ctx->begin, ctx->end);
  yyprintf((stderr, "  ok   %s @ %s\n", "grammar", ctx->buf+ctx->pos));
  return 1;
  l1:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "grammar", ctx->buf+ctx->pos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)(yycontext *ctx);

YY_PARSE(int) YYPARSEFROM(YY_CTX_PARAM_ yyrule yystart)
{
  int yyok;
  if (!yyctx->buflen)
    {
      yyctx->buflen= 1024;
      yyctx->buf= (char *)malloc(yyctx->buflen);
      yyctx->textlen= 1024;
      yyctx->text= (char *)malloc(yyctx->textlen);
      yyctx->thunkslen= 32;
      yyctx->thunks= (yythunk *)malloc(sizeof(yythunk) * yyctx->thunkslen);
      yyctx->valslen= 32;
      yyctx->vals= (YYSTYPE *)malloc(sizeof(YYSTYPE) * yyctx->valslen);
      yyctx->begin= yyctx->end= yyctx->pos= yyctx->limit= yyctx->thunkpos= 0;
    }
  yyctx->begin= yyctx->end= yyctx->pos;
  yyctx->thunkpos= 0;
  yyctx->val= yyctx->vals;
  yyok= yystart(yyctx);
  if (yyok) yyDone(yyctx);
  yyCommit(yyctx);
  return yyok;
}

YY_PARSE(int) YYPARSE(YY_CTX_PARAM)
{
  return YYPARSEFROM(YY_CTX_ARG_ yy_grammar);
}

#endif
 

VALUE liquid_context_parse_impl(VALUE self, VALUE text) {
  char *p; 
  int len; 
  yycontext ctx;  

  memset(&ctx, 0, sizeof(yycontext));
  ctx.p = RSTRING_PTR(text);  
  ctx.p_len = (int) RSTRING_LEN(text);
  ctx.rb_tokens = rb_ary_new();

  yyprintf((stderr, "About to start: %s %d\n", ctx.p, ctx.p_len));
  
  //while(yyparse(&ctx))
  //  ;
  
  yyparse(&ctx);
  yyparse(&ctx);
  yyparse(&ctx);

  return ctx.rb_tokens;
}
