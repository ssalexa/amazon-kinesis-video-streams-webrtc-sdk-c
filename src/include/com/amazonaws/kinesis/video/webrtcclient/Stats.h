/*
 * Profiler public include file
 */
#ifndef __KINESIS_VIDEO_WEBRTCCLIENT_STATS_INCLUDE__
#define __KINESIS_VIDEO_WEBRTCCLIENT_STATS_INCLUDE__

#pragma once

#ifdef  __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////
// Public headers
////////////////////////////////////////////////////

#define MAX_TRANSPORT_ID_LENGTH                   8U
#define MAX_LOCALCANDIDATE_ID_LENGTH              8U
#define MAX_REMOTECANDIDATE_ID_LENGTH             8U
#define MAX_IPV4_ADDRESS_LENGTH                   4U
#define MAX_IPV6_ADDRESS_LENGTH                   16U
#define MAX_RELAY_PROTOCOL_LENGTH                 8U
#define MAX_TLS_VERSION_LENGTH                    8U
#define MAX_DTLS_CIPHER_LENGTH                    64U
#define MAX_SRTP_CIPHER_LENGTH                    64U
#define MAX_TLS_GROUP_LENGHTH                     32U
#define MAX_PROTOCOL_LENGTH                       8U

#define MAX_STRING_LENGTH                         255U

typedef enum {
    CANDIDATE_PAIR,
    CERTIFICATE,
    CODEC,
    CSRC,
    DATA_CHANNEL,
    INBOUND_RTP,
    LOCAL_CANDIDATE,
    OUTBOUND_RTP,
    PEER_CONNECTION,
    RECEIVER,
    REMOTE_CANDIDATE,
    REMOTE_INBOUND_RTP,
    REMOTE_OUTBOUND_RTP,
    SENDER,
    STREAM,
    TRACK,
    TRANSPORT,
    SIGNALING_CLIENT,
    RTC_ALL
} RTCStatsType;

typedef enum {
    FROZEN,
    WAITING,
    INPROGRESS,
    FAILED,
    SUCCEEDED
} RTCStatsIceCandidatePairState;

typedef enum {
    UNKNOWN,
    CONTROLLING,
    CONTROLLED
} RTCIceRole;

typedef enum {
    NEW,
    CONNECTING,
    CONNECTED,
    CLOSED,
    FAIL
} RTCDtlsTransportState;

typedef enum {
    NONE,
    CPU,
    BANDWIDTH,
    OTHER,
} RTCQualityLimitationReason;

typedef struct {
    UINT64 durationInSeconds;
    RTCQualityLimitationReason qualityLimitationReason;
} qualityLimitationDurationsRecord, *PQualityLimitationDurationsRecord;

typedef struct {
    CHAR dscp[MAX_STRING_LENGTH + 1];
    UINT64 totalNumberOfPacketsSent;
} perDscpPacketsSentRecord, *PperDscpPacketsSentRecord;

typedef struct {
    CHAR transportId[MAX_TRANSPORT_ID_LENGTH + 1];
    CHAR localCandidateId[MAX_LOCALCANDIDATE_ID_LENGTH + 1];
    CHAR remoteCandidateId[MAX_REMOTECANDIDATE_ID_LENGTH + 1];
    RTCStatsIceCandidatePairState state;
    BOOL nominated;
    UINT32 circuitBreakerTriggerCount;
    UINT32 packetsDiscardedOnSend;
    UINT64 packetsSent;
    UINT64 packetsReceived;
    UINT64 bytesSent;
    UINT64 bytesReceived;
    UINT64 lastPacketSentTimestamp;
    UINT64 lastPacketReceivedTimestamp;
    UINT64 firstRequestTimestamp;
    UINT64 lastRequestTimestamp;
    UINT64 lastResponseTimestamp;
    UINT64 totalRoundTripTime;
    UINT64 currentRoundTripTime;
    UINT64 availableOutgoingBitrate;
    UINT64 availableIncomingBitrate;
    UINT64 requestsReceived;
    UINT64 requestsSent;
    UINT64 responsesReceived;
    UINT64 responsesSent;
    UINT64 retransmissionsReceived;
    UINT64 retransmissionsSent;
    UINT64 consentRequestsSent;
    UINT64 consentExpiredTimestamp;
    UINT64 bytesDiscardedOnSend;
} RTCIceCandidatePairStats, *PRTCIceCandidatePairStats;

typedef struct {
    CHAR url[MAX_STRING_LENGTH + 1];
    CHAR protocol[MAX_STRING_LENGTH + 1];
    INT32 port;
    UINT64 totalRequestsSent;
    UINT64 totalResponsesReceived;
    UINT64 totalRoundTripTime;
} RTCIceServerStats, *PRTCIceServerStats;

typedef struct {
    CHAR transportId[MAX_TRANSPORT_ID_LENGTH + 1];
    CHAR ipV4address[MAX_IPV4_ADDRESS_LENGTH + 1];
    CHAR ipV6address[MAX_IPV6_ADDRESS_LENGTH + 1];
    CHAR protocol[MAX_PROTOCOL_LENGTH + 1]; //Valid values: TCP, UDP
    CHAR relayProtocol[MAX_RELAY_PROTOCOL_LENGTH + 1]; // Valid values: UDP, TCP, TLS
    INT32 priority;
    INT32 port;
    CHAR url[MAX_STRING_LENGTH + 1];
} RTCIceCandidateStats, *PRTCIceCandidateStats;

typedef struct {
    CHAR rtcpTransportStatsId[MAX_STRING_LENGTH + 1];
    CHAR selectedCandidatePairId[MAX_STRING_LENGTH + 1];
    CHAR localCertificateId[MAX_STRING_LENGTH + 1];
    CHAR remoteCertificateId[MAX_STRING_LENGTH + 1];
    CHAR tlsVersion[MAX_TLS_VERSION_LENGTH + 1];
    CHAR dtlsCipher[MAX_DTLS_CIPHER_LENGTH + 1];
    CHAR srtpCipher[MAX_SRTP_CIPHER_LENGTH + 1];
    CHAR tlsGroup[MAX_TLS_GROUP_LENGHTH + 1];
    RTCIceRole iceRole;
    RTCDtlsTransportState dtlsState;
    UINT64 packetsSent;
    UINT64 packetsReceived;
    UINT64 bytesSent;
    UINT64 bytesReceived;
    UINT32 selectedCandidatePairChanges;
} RTCTransportStats, *PRTCTransportStats;

typedef struct {
    BOOL voiceActivityFlag;
    CHAR trackId[MAX_STRING_LENGTH + 1];
    CHAR mediaSourceId[MAX_STRING_LENGTH + 1];
    CHAR senderId[MAX_STRING_LENGTH + 1];
    CHAR remoteId[MAX_STRING_LENGTH + 1];
    CHAR rid[MAX_STRING_LENGTH + 1];
    CHAR encoderImplementation[MAX_STRING_LENGTH + 1];
    UINT32 packetsDiscardedOnSend;
    UINT32 framesSent;
    UINT32 hugeFramesSent;
    UINT32 framesEncoded;
    UINT32 keyFramesEncoded;
    UINT32 framesDiscardedOnSend;
    UINT32 frameWidth;
    UINT32 frameHeight;
    UINT32 frameBitDepth;
    UINT32 nackCount;
    UINT32 firCount;
    UINT32 pliCount;
    UINT32 sliCount;
    UINT32 qualityLimitationResolutionChanges;
    INT32 fecPacketsSent;
    UINT64 lastPacketSentTimestamp;
    UINT64 headerBytesSent;
    UINT64 bytesDiscardedOnSend;
    UINT64 retransmittedPacketsSent;
    UINT64 retransmittedBytesSent;
    UINT64 targetBitrate;
    UINT64 totalEncodedBytesTarget;
    UINT64 framesPerSecond;
    UINT64 qpSum;
    UINT64 totalSamplesSent;
    UINT64 samplesEncodedWithSilk;
    UINT64 samplesEncodedWithCelt;
    UINT64 totalEncodeTime;
    UINT64 totalPacketSendDelay;
    UINT64 averageRtcpInterval;
    PQualityLimitationDurationsRecord qualityLimitationDurations;
    perDscpPacketsSentRecord perDscpPacketsSent;
    RTCQualityLimitationReason qualityLimitationReason;
} RTCOutboundRtpStreamStats, *PRTCOutboundRtpStreamStats;

typedef struct {
    CHAR localId[MAX_STRING_LENGTH + 1];
    UINT64 roundTripTime;
    UINT64 totalRoundTripTime;
    UINT64 fractionLost;
    UINT64 reportsReceived;
    UINT64 roundTripTimeMeasurements;
} RTCRemoteInboundRtpStreamStats, *PRTCRemoteInboundRtpStreamStats;

typedef struct {
    UINT64 apiCallLatency;
    UINT64 signalingClientUptime;
    UINT64 connectionDuration;
    UINT64 numberOfMessagesSent;
    UINT64 iceRefreshCount;
}SignalingClientMetrics, PSignalingClientMetrics;

typedef struct {
	RTCIceCandidatePairStats
    RTCIceCandidateStats iceCandidateStats;
    RTCTransportStats transportStats;
    RTCOutboundRtpStreamStats remoteOutboundRtpStreamStats;
    RTCRemoteInboundRtpStreamStats remoteInboundRtpStreamStats;
    RTCIceCandidatePairStats candidatePairStats;
} WebRTCStats, *PWebRTCStats;

#ifdef  __cplusplus
}
#endif
#endif /* __KINESIS_VIDEO_WEBRTCCLIENT_STATS_INCLUDE__ */
