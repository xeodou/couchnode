#ifndef NETBUF_DEFS_H
#define NETBUF_DEFS_H

typedef struct netbuf_st nb_MGR;
typedef unsigned int nb_SIZE;

/**
 * @file
 * Netbuf Core Structures
 * @addtogroup NETBUFS
 * @{
 */

/**
 * @name Cache Allocation
 * @{
 *
 * The following settings control the default allocation policy.
 * Each allocator pool has both blocks and the amount of data per block.
 *
 * Multiple blocks help with cache locality when traversing, while large
 * data segements allow each individual element to be spaced near the next.
 */

/** @brief How many blocks to preallocate for SNDQ elements, per manager */
#define NB_SNDQ_CACHEBLOCKS 4
/** @brief How many SNDQELEM structures per block */
#define NB_SNDQ_BASEALLOC 128


/** @brief How many dealloc blocks to allocated per MBLOCK */
#define NB_MBDEALLOC_CACHEBLOCKS 0
/** @brief Number of dealloc structures per block */
#define NB_MBDEALLOC_BASEALLOC 24


/** @brief How many data blocks to allocate per manager */
#define NB_DATA_CACHEBLOCKS 16
/** @brief Default data allocation size */
#define NB_DATA_BASEALLOC 32768
/**@}*/

typedef struct {
    nb_SIZE sndq_cacheblocks;
    nb_SIZE sndq_basealloc;
    nb_SIZE dea_cacheblocks;
    nb_SIZE dea_basealloc;
    nb_SIZE data_cacheblocks;
    nb_SIZE data_basealloc;
} nb_SETTINGS;

#ifndef _WIN32
typedef struct {
    void *iov_base;
    size_t iov_len;
} nb_IOV;

/**Macro which serves as a static initializer for an nb_IOV. This works
 * on both Windows and Unix despite the layout of the structure being different
 */
#define NETBUF_IOV_INIT(base, len) { base, len }
#else
typedef struct {
    ULONG iov_len;
    void *iov_base;
} nb_IOV;
#define NETBUF_IOV_INIT(base, len) { len, base }
#endif

/**@}*/

#endif /* NETBUF_DEFS_H */
