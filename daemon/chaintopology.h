#ifndef LIGHTNING_DAEMON_CHAINTOPOLOGY_H
#define LIGHTNING_DAEMON_CHAINTOPOLOGY_H
#include "config.h"
#include <stddef.h>

struct lightningd_state;
struct txwatch;

/* This is the number of blocks which would have to be mined to invalidate
 * the tx. */
size_t get_tx_depth(struct lightningd_state *dstate, const struct txwatch *w);

/* This is the worst-case (latest) mediantime of blocks including the txid.
 * Assumes the depth is > 0! */
u32 get_last_mediantime(struct lightningd_state *dstate,
			const struct sha256_double *txid);

/* Get mediantime of the tip; if more than one, pick greatest time. */
u32 get_tip_mediantime(struct lightningd_state *dstate);

void setup_topology(struct lightningd_state *dstate);

#endif /* LIGHTNING_DAEMON_CRYPTOPKT_H */
